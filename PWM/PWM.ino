void setup() {
  // Initialize pin 9 as an output
  pinMode(9, OUTPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Increase duty cycle from 0 to 255
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(9, dutyCycle);
    Serial.println(dutyCycle);  // Print only the duty cycle value
    delay(10); // Small delay to observe the change
  }
  
  // Decrease duty cycle from 255 to 0
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    analogWrite(9, dutyCycle);
    Serial.println(dutyCycle);  // Print only the duty cycle value
    delay(10); // Small delay to observe the change
  }
}
