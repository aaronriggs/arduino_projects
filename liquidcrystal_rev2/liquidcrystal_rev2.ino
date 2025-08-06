//   The circuit:
//  * LCD RS pin to digital pin 7
//  * LCD Enable pin to digital pin 8
//  * LCD D4 pin to digital pin 9
//  * LCD D5 pin to digital pin 10
//  * LCD D6 pin to digital pin 11
//  * LCD D7 pin to digital pin 12
//  * LCD R/W pin to ground
//  * LCD VSS pin to ground
//  * LCD VCC pin to 5V
//  * 10K resistor:
//  * ends to +5V and ground
//  * wiper to LCD VO pin (pin 3) - controls contrast


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, friend");
}

void loop() {
  delay(2000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Hi           ");
  lcd.setCursor(0, 1);
  lcd.print("Friend");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("You're");
  lcd.setCursor(0, 1);
  lcd.print("Awesome :)");
  delay(2000);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}