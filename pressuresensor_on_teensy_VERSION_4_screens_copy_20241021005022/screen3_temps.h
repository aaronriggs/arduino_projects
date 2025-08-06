void oiltemp(char *text, uint16_t color) { 
  pressureValue = analogRead(pressureInput2); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,80);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
}

void transtemp(char *text, uint16_t color) { 
  pressureValue = analogRead(pressureInput3); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,130);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
}

void coolanttemp(char *text, uint16_t color) { 
  pressureValue = analogRead(pressureInput4); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,180);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(500);
}

void intakeairtemp(char *text, uint16_t color) { 
  pressureValue = analogRead(pressureInput4); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,30);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(500);
}
