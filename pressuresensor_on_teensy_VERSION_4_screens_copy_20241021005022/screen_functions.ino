void projecttitle(char *text, uint16_t color) {
  tft.setCursor(15,30); 
  tft.setTextColor(WHITE, BLACK);
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

void drawsensortitle(char *text, uint16_t color) {
  tft.setCursor(10, 10); 
  tft.setTextColor(RED);
  tft.setTextSize(2);
  tft.print("OIL PRESSURE "); //Oil Pressure
  tft.setCursor(10, 60); 
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("OIL TEMP "); //Oil Temp
  tft.setCursor(10, 110); 
  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  tft.print("TRANS TEMP "); //Transmission Temp
  tft.setCursor(10, 160); 
  tft.setTextColor(BLUE);
  tft.setTextSize(2);
  tft.print("COOLANT TEMP "); //Coolant temp
  tft.setCursor(210, 10); 
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.print("VOLTS "); //Vehicle Voltage
  tft.setCursor(170, 60); 
  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  tft.print("Ambient Temp"); //Ambient Voltage
  tft.setCursor(160, 110); 
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("Fuel Pressure"); //Fuel Pressure

}
