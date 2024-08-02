#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

// Define pin numbers
int light = 8;

// Initialize states
bool LIGHT_ON = false;

// Create VoiceRecognition object
VR myVR(2, 3); // RX, TX

uint8_t buf[64];

void printSignature(uint8_t *buf, int len) {
  for (int i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    } else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf) {
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  } else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  } else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  } else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup() {
  myVR.begin(9600);
  Serial.begin(115200);
  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("VoiceRecognitionModule not found.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  myVR.load((uint8_t)0); // Load "Light On" command
  myVR.load((uint8_t)1); // Load "Light Off" command
  myVR.load((uint8_t)100); // Load additional "Light Off" command

  pinMode(light, OUTPUT);
  digitalWrite(light, LOW);
}

void loop() {
  int ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    printVR(buf);
    
    // "Light On" command
    if (buf[1] == 0) {
      digitalWrite(light, HIGH);
      Serial.println("Light ON");
      LIGHT_ON = true;
    }

    // "Light Off" command
    if (buf[1] == 1 || buf[1] == 100) {
      digitalWrite(light, LOW);
      Serial.println("Light OFF");
      LIGHT_ON = false;
    }
  }
}
