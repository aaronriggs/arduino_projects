void oilpressure(char *text, uint16_t color) { //now acts as one "screen"
  pressureValue = analogRead(pressureInput1); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,30);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(50);
}

void oiltemp(char *text, uint16_t color) { //now acts as one "screen"
  pressureValue = analogRead(pressureInput2); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,80);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
}