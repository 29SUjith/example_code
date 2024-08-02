#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Wire.h>
#include <Adafruit_GFX.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello");
  display.setCursor(0,15);
  display.println("Everyone");
  display.display();
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
display.clearDisplay();
/*

display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("SUJITH");
display.setCursor(0,15);
display.println("Here");
display.display();
delay(3000);*/


}
