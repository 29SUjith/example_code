
char receivedChar;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT); // Set pin 13 as an output
   digitalWrite(6, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read(); // Read a character from Bluetooth
    Serial.println(receivedChar);
    // Check the received character
    if (receivedChar == 'A') {
      digitalWrite(6, LOW); // Set pin 13 HIGH
      
    } else if (receivedChar == 'B') {
      digitalWrite(6, HIGH); // Set pin 13 LOW
      
    } else{
      digitalWrite(6, HIGH);
    }

  }
}