void transtemp(char *text, uint16_t color) { //now acts as one "screen"
  pressureValue = analogRead(pressureInput3); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,130);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
}
