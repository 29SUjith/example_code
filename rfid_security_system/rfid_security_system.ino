#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>  // Include the Servo library

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

Servo myServo;  // Create a Servo object

// Define the valid UID (for example, your provided UID: 83 EA 6C 14)
byte validUID[] = { 0x83, 0xEA, 0x6C, 0x14 };  // Replace this with the UID of your allowed card

void setup() {
  Serial.begin(9600);
  SPI.begin();  // Init SPI bus
  rfid.PCD_Init();  // Init RC522 
  myServo.attach(6);  // Attach the servo to pin 6
  myServo.write(0);  // Initialize the servo at 0 degrees
}

void loop() {
  // Reset the loop if no new card is present on the sensor/reader
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been read
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  // Print RFID UID for debugging
  Serial.print(F("RFID Tag UID:"));
  printHex(rfid.uid.uidByte, rfid.uid.size);
  Serial.println("");

  // Check if the detected UID matches the valid UID
  if (isUIDValid(rfid.uid.uidByte, rfid.uid.size)) {
    // Move the servo from 0 to 90 degrees if the UID matches
    myServo.write(0);  // Move the servo to 90 degrees
    delay(4000);  // Wait for 1 second
    myServo.write(180);  // Move the servo back to 0 degrees
    delay(1000);  // Wait for 1 second
    Serial.println("Valid RFID Tag detected.");
  } else {
    // If the UID is not valid, do nothing (servo will stay at 0 degrees)
    Serial.println("Invalid RFID Tag detected.");
  }

  rfid.PICC_HaltA();  // Halt PICC
}

// Routine to dump a byte array as hex values to Serial
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

// Function to check if the detected UID matches the valid one
bool isUIDValid(byte *uid, byte uidSize) {
  if (uidSize != sizeof(validUID)) {
    return false;  // If the UID size doesn't match, return false
  }
  
  for (byte i = 0; i < uidSize; i++) {
    if (uid[i] != validUID[i]) {
      return false;  // If any byte doesn't match, return false
    }
  }
  
  return true;  // UID matches the valid one
}
