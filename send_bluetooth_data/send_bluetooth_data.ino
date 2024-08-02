#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11); // RX, TX pins for Bluetooth module

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600); // Default baud rate for HC-05 module
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    char data = bluetoothSerial.read();
    Serial.print(data); // Print received data to the serial monitor

    // Check if the received data is 'T', 'E', 'D', 'x', 'T' (TEDxT)
    if (data == 'A') {
      // Assuming you want to send "Hello, TEDx!" as a response
      bluetoothSerial.print("Hello, TEDx!");
    }
  }

  // Add your other code/logic here

}
