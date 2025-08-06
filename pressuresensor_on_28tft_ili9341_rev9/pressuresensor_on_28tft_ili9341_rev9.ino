//must use adafruit gfx 1.5.3 to compile, newer versions broke tftlcd
//need to vary sensor update times, need millis
//need to turn images into sprites
#include <Adafruit_TFTLCD.h> 
#include "logo.h" //logo bitmap here
#include "inputs.h" //sensor inputs here
#include "splashscreen.h" //hbms splashscrren logo here

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

//function wait definitions, set values for each sensor 
#define SENSOR_INTERVAL1 700 //oil pressure
#define SENSOR_INTERVAL2 1100 //oil temp
#define SENSOR_INTERVAL3 1300 //trans temp
#define SENSOR_INTERVAL4 1200 //coolant temp
#define SENSOR_INTERVAL5 2200 //voltage
#define SENSOR_INTERVAL6 10000 //ambient temp
#define SENSOR_INTERVAL7 1250 //fuel pressure
unsigned long time_1 = 0;
unsigned long time_2 = 0;
unsigned long time_3 = 0;
unsigned long time_4 = 0;
unsigned long time_5 = 0;
unsigned long time_6 = 0;
unsigned long time_7 = 0;

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//sensor inputs were here, moved to inputs.h
//bring functions over from tabs, must call otherwise random errors can occur
void oilpressure();
void oiltemp();
void transtemp();
void coolanttemp();
void voltage();
void ambientairtemp();
void fuelpressure();
void projecttitle();
void drawsensortitle();
void AllSensorScreen();

void setup() {
  tft.begin(0x9341); //must include this begin point for ili9341
  tft.setRotation(1);
  tft.fillScreen(WHITE); 
  projecttitle("Pressure Project ", WHITE);
  delay(500);
  projecttitle_clear("Pressure Project ", WHITE);
  delay(200);
  tft.drawBitmap(30, 20, SPLASH, 250, 200, BLACK); //WHOLE SCREEN IMAGE, if black, white, very slow draw
  delay(2000);
  tft.fillScreen(BLACK); // way faster than drawing a black bitmap 
  tft.drawBitmap(240, 165, Badger, 72, 72, WHITE); //bottom right
  drawsensortitle("", WHITE); //must declare color but color set in function
  //tft.drawBitmap(240, 165, Badger, 72, 72, WHITE); //bottom right
}

void loop() {
    if(millis() >= time_1 + SENSOR_INTERVAL1){
      time_1 +=SENSOR_INTERVAL1;
      oilpressure("", WHITE); //oil pressure
    }

    if(millis() >= time_2 + SENSOR_INTERVAL2){
      time_2 +=SENSOR_INTERVAL2;
      oiltemp("", WHITE); //oil temp
    }

    if(millis() >= time_3 + SENSOR_INTERVAL3){
      time_3 +=SENSOR_INTERVAL3;
      transtemp("", WHITE); //trans temp
    }

    if(millis() >= time_4 + SENSOR_INTERVAL4){
      time_4 +=SENSOR_INTERVAL4;
      coolanttemp("", WHITE); //coolant temp
    }
    
    if(millis() >= time_5 + SENSOR_INTERVAL5){
      time_5 +=SENSOR_INTERVAL5;
      voltage("", WHITE); //voltage
    }

    if(millis() >= time_6 + SENSOR_INTERVAL6){
      time_6 +=SENSOR_INTERVAL6;
      ambientairtemp("", WHITE); //ambient air temp
    }

    if(millis() >= time_7 + SENSOR_INTERVAL7){
      time_7 +=SENSOR_INTERVAL7;
      fuelpressure("", WHITE); //fuel pressure
    }
}
