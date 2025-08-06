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

//sensor and code taken from ovens garage
const int pressureInput = A1; //select the analog input pin for the pressure transducer
const int pressureZero = 102.4; //analog reading of pressure transducer at 0psi
const int pressureMax = 921.6; //analog reading of pressure transducer at 100psi
const int pressuretransducermaxPSI = 100; //psi value of transducer being used
float pressureValue = 0; //variable to store the value coming from the pressure transducer

void setup() {
  Serial.begin(9600);
  Serial.print("hello!");
  tft.begin();
  tft.fillScreen(BLACK); 
  projecttitle("Pressure Project ", WHITE);
  delay(500);
  tft.fillScreen(BLACK);
  pressuresensortitle("Transducer Pressure ", WHITE);
}

void loop() {
  drawpressurevalue("", WHITE);
  delay(400);
}

void drawpressurevalue(char *text, uint16_t color) {
  pressureValue = analogRead(pressureInput); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(20,65);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
}

void projecttitle(char *text, uint16_t color) {
  tft.setCursor(15,30); 
  tft.setTextColor(color);
  tft.setTextSize(1);
  tft.print(text);
}

void pressuresensortitle(char *text, uint16_t color) {
  tft.setCursor(10,30); 
  tft.setTextColor(color);
  tft.setTextSize(1);
  tft.print(text);
}