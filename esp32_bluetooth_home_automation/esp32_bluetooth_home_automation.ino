#include <BluetoothSerial.h>

#define RELAY_PIN 2 // Pin connected to the relay module
#define RELAY_PIN2 4
BluetoothSerial SerialBT;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PIN2,OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("ESP32_CircuitBreaker"); // Bluetooth device name

  Serial.println("ESP32 Circuit Breaker Initialized");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    if (command == 'A') {
      turnOnRelay();
    } else if (command == 'B') {
      turnOffRelay();
    }
      else if (command == 'C') {
      turnOnRelay2();
    } else if (command == 'D') {
      turnOffRelay2();
    }
  }
}

void turnOnRelay() {
  digitalWrite(RELAY_PIN, LOW);
  Serial.println("Circuit turned ON");
}

void turnOffRelay() {
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("Circuit turned OFF");
}

void turnOnRelay2() {
  digitalWrite(RELAY_PIN2, LOW);
  Serial.println("Circuit2 turned ON");
}

void turnOffRelay2() {
  digitalWrite(RELAY_PIN2, HIGH);
  Serial.println("Circuit2 turned OFF");
}
