#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128 

#define SCLK_PIN 13
#define MOSI_PIN 11
#define DC_PIN   7
#define CS_PIN   10
#define RST_PIN  8

#define	BLACK           0x0000
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

Adafruit_SSD1351 tft = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
  Serial.print("hello!");
  tft.begin();
  tft.fillScreen(BLACK); 
  testdrawtext("Thermistor Project ", WHITE);
  delay(500);
  tft.fillScreen(BLACK);
  testdrawtext("Thermistor Temp: ", WHITE);
}

void loop() {
  thermistormath();
  testdrawtemp("", WHITE);
  delay(300);
}

void thermistormath() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(20,30); 
  tft.setTextColor(color);
  tft.setTextSize(1);
  tft.print(text);
}

void testdrawtemp(char *text, uint16_t color) {
  tft.setCursor(20,65);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(Tf);
}