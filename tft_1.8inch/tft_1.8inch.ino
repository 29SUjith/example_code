#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        8 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

float p = 3.1415926;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
tft.initR(INITR_BLACKTAB);  
 tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:
tft.setRotation(10);
tft.setTextSize(2);
tft.setCursor(5, 50);
tft.setTextColor(ST77XX_RED);
tft.print("HELLO GUYS");

delay(1000);

tft.fillScreen(ST77XX_WHITE);

delay(500);

tft.setRotation(10);
tft.setTextSize(2);
tft.setCursor(25, 50);
tft.setTextColor(ST77XX_GREEN);
tft.println("HOW ARE");
tft.setCursor(30,70);
tft.println("YOU?");

delay(1000);

tft.fillScreen(ST77XX_WHITE);

delay(500);


}
