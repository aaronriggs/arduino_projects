//see inputs.h for more information on variable names

void oilpressure(char *text, uint16_t color) 
{ 
  pressureValue = analogRead(pressureInput1); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,30);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(50);
};

void oiltemp(char *text, uint16_t color) { //change to thermistor
  pressureValue = analogRead(pressureInput2); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,80);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
};

void transtemp(char *text, uint16_t color) { //change to thermistor
  pressureValue = analogRead(pressureInput3); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,130);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(100);
}

void coolanttemp(char *text, uint16_t color) { //change to thermistor
  pressureValue = analogRead(pressureInput4); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(10,180);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(500);
}

void voltage(char *text, uint16_t color) //needs an analog read
{ 
  voltage_value = analogRead(voltage_val1);
  tft.setCursor(195,30);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(voltage_value/1000); //reading directly from pin in millivolts
  //delay(500);
}

void ambientairtemp(char *text, uint16_t color) { //change to thermistor
  pressureValue = analogRead(pressureInput6); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(195, 80);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue);
  //delay(500);
}

void fuelpressure(char *text, uint16_t color) 
{ 
  pressureValue = analogRead(pressureInput1); //reads value from input pin and assigns to variable
  pressureValue = ((pressureValue-pressureZero)*pressuretransducermaxPSI)/(pressureMax-pressureZero); 
  //conversion equation to convert analog reading to psi
  tft.setCursor(195,130);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(3);
  tft.print(pressureValue); //can subtract from this value to bring closer to 0 with no pressure
  //delay(50);
};
