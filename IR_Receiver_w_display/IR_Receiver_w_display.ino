//must use adafruit gfx 1.5.3 to compile, newer versions broke tftlcd
//using ATMEGA
#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <IRremote.h>

//LCD SETUP
#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

//IR pin setup
#define IR_RECEIVE_PIN 45

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

void projecttitle(char *text, uint16_t color) 
{
  tft.setCursor(15,30); 
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(text);
  delay(100);
}

void projectvalues_text(char *text, uint16_t color) 
{
  tft.setCursor(15,75); 
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(1);
  tft.print(text);
  delay(100);
}

void projecttitle_clear(char *text, uint16_t color) 
{
  tft.setCursor(15,30); 
  tft.setTextColor(WHITE, WHITE);
  tft.setTextSize(3);
  tft.print(text);
  delay(100);
}

void projectvalues_clear(char *text, uint16_t color) 
{
  tft.setCursor(15,75); 
  tft.setTextColor(WHITE, WHITE);
  tft.setTextSize(1);
  tft.print(text);
  delay(100);
}


IRrecv irrecv(45);      // IR module is connected to pin 2
decode_results results; // create a variable of type decode_results

void setup() 
{
  tft.begin(0x9341); //must include this begin point
  Serial.begin(115200);
  tft.setRotation(1);
  tft.fillScreen(BLACK); 
  projecttitle("IR Receiver ", WHITE);
  delay(1000);
  projecttitle_clear("IR Receiver ", BLACK);
  delay(2000);
  tft.fillScreen(BLACK);
  irrecv.enableIRIn(); // initialize irrecv
}

int project_values = 0;


void loop()
{
projecttitle("IR value: ", WHITE);
project_values = 0;
if (irrecv.decode(&results)) {
    delay (500);
    Serial.println(results.value, HEX);
    project_values = (results.value, HEX);
    delay (1000);
    projectvalues_text("", project_values);   // get and decode IR pulses received by the module
    
    tft.fillScreen(BLACK);   
    irrecv.resume();                      // get the next value
  }
delay (100);
projectvalues_clear(results.value, HEX);
  // if (irrecv.decode(&results)) {
  //   Serial.println(results.value, HEX);   // get and decode IR pulses received by the module
  //   irrecv.resume();                      // get the next value
  // }
  // delay (100);    // wait 100 milliSeconds
}

