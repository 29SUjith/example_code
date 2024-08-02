#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int receivedAngle = Serial.parseInt();  // Read the integer angle from the serial buffer
    Serial.print("Received angle: ");
    Serial.println(receivedAngle);

    // Add code here to handle the received angle
    // For example, you can control a servo motor or perform other actions based on the angle
  }
}
