#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int finc;
int fdec;
int type;
int select;
int j=0;

#define CHANNEL_NUMBER 8
#define PPM_FRAME_LENGTH 22500  // Frame length in microseconds (22.5ms for 8 channels)
#define PULSE_LENGTH 300        // Pulse length in microseconds

// Channel values array (in microseconds)
int ppm[CHANNEL_NUMBER];

// Output pin for PPM signal


const int sWavePin = 9; // Pin to output the sine wave
const int tWavePin = 10; // Pin to output the triangle wave
const int sqWavePin = 11;
int frequency = 1; // Frequency in Hz
const int samples = 100; // Number of samples per period
const int amplitude = 127; // Amplitude of the sine wave (127 for 0-255 range)
const int offset = 128; // Offset to center the sine wave in the 0-255 range
const int period = 1000000 / (frequency * samples); // Period in microseconds per sample

const int steps = 255; // Number of steps in the triangle wave
const int period1 = 1000000 / (frequency * 2 * steps); // Period in microseconds per step


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(sWavePin, OUTPUT);
  pinMode(tWavePin, OUTPUT);
  pinMode(sqWavePin, OUTPUT);
  digitalWrite(sWavePin, LOW);

    for (int i = 0; i < CHANNEL_NUMBER; i++) {
      ppm[i] = 1500; // Default to 1.5ms
    }

      // Configure Timer1
    cli(); // Disable interrupts
    TCCR1A = 0; // Clear registers
    TCCR1B = 0;
    TCNT1 = 0;

    // Set compare match register for 1kHz increments
    OCR1A = 1000;
    // Turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 64 prescaler
    TCCR1B |= (1 << CS10) | (1 << CS11);
    // Enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei(); // Enable interrupts
  }

  ISR(TIMER1_COMPA_vect) {
    static boolean state = true;
    static unsigned int currentChannel = 0;
    static unsigned long remainingFrameLength = PPM_FRAME_LENGTH;

    // Toggle the output pin
    digitalWrite(sWavePin, state);
    state = !state;

    // If the state is high (pulse end)
    if (state) {
      OCR1A = PULSE_LENGTH;
    } else {
      // If the state is low (pulse start)
      if (currentChannel >= CHANNEL_NUMBER) {
        OCR1A = remainingFrameLength;
        currentChannel = 0;
        remainingFrameLength = PPM_FRAME_LENGTH;
      } else {
        OCR1A = ppm[currentChannel] - PULSE_LENGTH;
        remainingFrameLength -= ppm[currentChannel];
        currentChannel++;
      }
    }
  }



void generatePPM() {
  // Update ppm[] values here (example)
  for (int i = 0; i < CHANNEL_NUMBER; i++) {
    ppm[i] = 1000 + i * 100; // Example: Increasing PPM values
  }

  // Print the current PPM values to the Serial Plotter
  for (int i = 0; i < CHANNEL_NUMBER; i++) {
    Serial.print(ppm[i]);
    if (i < CHANNEL_NUMBER - 1) {
      Serial.print(",");
    }
  }
  Serial.println();
}
void swave(){
    for (int i = 0; i < samples; i++) {
      float angle = 2 * PI * i / samples; // Calculate the angle for this sample
      int value = offset + amplitude * sin(angle); // Calculate the sine value
      analogWrite(sqWavePin, value); // Set the PWM duty cycle
      Serial.println(value); // Print the value for the Serial Plotter
      delayMicroseconds(period); // Wait for the period per sample
    }
  }


void twave(){
    for (int t = 0; t <= steps; t++) {
      analogWrite(sqWavePin, t); // Set the PWM duty cycle
      Serial.println(t); // Print the value for the Serial Plotter
      delayMicroseconds(period1); // Wait for the period per step
    }

    // Generate the falling edge of the triangle wave
    
    for (int t = steps; t >= 0; t--) {
      analogWrite(sqWavePin, t); // Set the PWM duty cycle
      Serial.println(t); // Print the value for the Serial Plotter
      delayMicroseconds(period1); // Wait for the period per step
    }
}

void sqwave(){
  digitalWrite(sqWavePin, HIGH);
  Serial.println(255);
  delayMicroseconds(period/2); // Half period for HIGH state
  digitalWrite(sqWavePin, LOW);
  Serial.println(0);
  delayMicroseconds(period/2); // Half period for LOW state
}

void loop() {
  // put your main code here, to run repeatedly:
  finc=digitalRead(A2);
  Serial.print("f+ =");
  Serial.println(finc);

  fdec=digitalRead(A1);
  Serial.print("f- =");
  Serial.println(fdec);

  type=digitalRead(A0);
  Serial.print("type =");
  Serial.println(type);

  select=digitalRead(A3);
  Serial.print("select =");
  Serial.println(select);

  lcd.setCursor(0,0);
  lcd.print("Type=");
  lcd.setCursor(0,1);
  lcd.print("Freq=");
  lcd.setCursor(7,1);
  lcd.print(frequency);  
  lcd.setCursor(12,1);
  lcd.print("Hz");

  
  lcd.setCursor(15,0);
  lcd.print(j);

  Serial.print("j=");
  Serial.println(j);

  if(type==0 & j<3){
    j=j+1;
    delay(1000);
  }

  else if(j==3 & type==0){
    j=0;
    delay(500);
  }

  else if(finc==0 & frequency<90){
    frequency=frequency+10;
    delay(500);
  }
  else if(fdec==0 & frequency>9){
    frequency=frequency-10;
    delay(500);
  }

 
  if(j==1 & select==0){
    swave();
    lcd.setCursor(6,0);
    lcd.print(" Sine   ");
  }
  else if(j==2 & select==0){
    twave();
    lcd.setCursor(6,0);
    lcd.print(" PWM    ");
  }
  else if (j==3 & select==0){
    sqwave();
    lcd.setCursor(6,0);
    lcd.print(" square ");
  }

   if(j==1){
    lcd.setCursor(6,0);
    lcd.print(" sine   ");
  }
  else if(j==2 ){
    lcd.setCursor(6,0);
    lcd.print(" PWM    ");
  }
  else if (j==3){ 
    lcd.setCursor(6,0);
    lcd.print(" square ");
  }
  else if(j==0){
    lcd.setCursor(6,0);
    lcd.print(" None   ");
    digitalWrite(sqWavePin,LOW);

  }

 /* else{
    digitalWrite(sWavePin,LOW);
    digitalWrite(sqWavePin,LOW);
    digitalWrite(tWavePin,LOW);
    lcd.setCursor(6,0);
    lcd.print("None    ");
  }*/

 

  delay(00);
}
