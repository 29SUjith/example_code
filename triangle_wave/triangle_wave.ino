const int triangleWavePin = 9; // Pin to output the triangle wave
const int frequency = 100; // Frequency in Hz
const int steps = 255; // Number of steps in the triangle wave
const int period = 1000000 / (frequency * 2 * steps); // Period in microseconds per step

void setup() {
  pinMode(triangleWavePin, OUTPUT);
  Serial.begin(115200); // Initialize Serial communication at 115200 baud
}

void loop() {
  // Generate the rising edge of the triangle wave
  for (int i = 0; i <= steps; i++) {
    analogWrite(triangleWavePin, i); // Set the PWM duty cycle
    Serial.println(i); // Print the value for the Serial Plotter
    delayMicroseconds(period); // Wait for the period per step
  }

  // Generate the falling edge of the triangle wave
  
  for (int i = steps; i >= 0; i--) {
    analogWrite(triangleWavePin, i); // Set the PWM duty cycle
    Serial.println(i); // Print the value for the Serial Plotter
    delayMicroseconds(period); // Wait for the period per step
  }
}
