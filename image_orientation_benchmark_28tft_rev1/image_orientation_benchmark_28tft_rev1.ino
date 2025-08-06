//must use adafruit gfx 1.5.3 to compile, newer versions broke tftlcd
//need to vary sensor update times, need millis
//need to turn images into sprites
#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include "splashscreen.h" //hbms splashscrren logo here
#include "splashscreen2.h" //hbms splashscrren logo here
#include <SPI.h>

//LCD setup
#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 
//Color setup
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

unsigned long test1_white () {
  tft.setRotation(1);
  tft.fillScreen(0xFFFF);
  unsigned long start = micros();
  tft.drawBitmap(30, 20, SPLASH, 250, 200, 0x0000); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  return micros() - start;
  delay(3000);
}

unsigned long test2_black () {
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  unsigned long start = micros();
  tft.drawBitmap(30, 20, SPLASH2, 250, 200, WHITE); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  return micros() - start;
  delay(3000);
}

unsigned long test3_white_portrait () {
  tft.begin(0x9341); //must include this begin point
  tft.setRotation(0);
  tft.fillScreen(WHITE);
  unsigned long start = micros();
  tft.drawBitmap(10, 20, SPLASH, 250, 200, BLACK); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  return micros() - start;
  delay(3000);
}

unsigned long test4_black_portrait () {
  tft.begin(0x9341); //must include this begin point
  tft.setRotation(0);
  tft.fillScreen(BLACK);
  unsigned long start = micros();
  tft.drawBitmap(10, 20, SPLASH2, 250, 200, WHITE); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  return micros() - start;
  delay(3000);
}

unsigned long test2_whitegrayscale () {
  tft.setRotation(1);
  tft.fillScreen(0x0000);
  unsigned long start = micros();
  tft.drawGrayscaleBitmap(30, 20, SPLASH, 250, 200, 0xFFFF); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  return micros() - start;
  delay(3000);
}


void projecttitle(char *text, uint16_t color) {
  tft.setCursor(15,30); 
  tft.setTextColor(BLACK, WHITE);
  tft.setTextSize(3);
  tft.print(text);
  delay(100);
}

void projecttitle_clear(char *text, uint16_t color) {
  tft.setCursor(15,30); 
  tft.setTextColor(WHITE, WHITE);
  tft.setTextSize(3);
  tft.print(text);
  delay(100);
}

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); //must include this begin point
  tft.setRotation(1);
  tft.fillScreen(WHITE); 
  projecttitle("Benchmark ", WHITE);
  delay(800);
  projecttitle_clear("Benchmark ", WHITE);
  Serial.println(F("Benchmark                Time (microseconds)"));

  delay(500);
}

void loop() {
  Serial.print(F("test1_white              "));
  Serial.println(test1_white());
  delay(500);
  Serial.print(F("test2_black              "));
  Serial.println(test2_black());
  delay(500);
  Serial.print(F("test3_white_portrait              "));
  Serial.println(test3_white_portrait());
  delay(500);
  Serial.print(F("test4_black_portrait             "));
  Serial.println(test4_black_portrait());
  delay(500);
  Serial.print(F("test2_whitegrayscale             "));
  Serial.println(test2_whitegrayscale());
}
