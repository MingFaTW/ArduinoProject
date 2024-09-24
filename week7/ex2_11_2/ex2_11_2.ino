#include <LiquidCrystal.h>
int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;
LiquidCrystal lcd(49,48,47,43,42,41);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int x,y,value;
  lcd.setCursor(0,0);
  lcd.print("X=     Y=     ");
  lcd.setCursor(0,1);
  lcd.print("SW= ");
  value = analogRead(joyPinX);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  SWstate = digitalRead(SW);
  lcd.setCursor(2,0);
  lcd.print(x);
  lcd.setCursor(10,0);
  
  lcd.print(y);
  lcd.setCursor(3,1);
  lcd.print(SWstate);
  delay(30);
  
}
