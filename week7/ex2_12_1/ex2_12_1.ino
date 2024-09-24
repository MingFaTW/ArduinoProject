#include <LiquidCrystal.h>
LiquidCrystal lcd(49,48,47,43,42,41);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("How are you?");
  lcd.setCursor(0,1);
  lcd.print("LCD Testing!");
}

void loop() {
  // put your main code here, to run repeatedly: 
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
}
