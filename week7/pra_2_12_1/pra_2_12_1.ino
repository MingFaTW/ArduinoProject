#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
                              {'F','E','D','C'},
                              {'B','3','6','9'},
                              {'A','2','5','8'},
                              {'0','1','4','7'}};
                              
byte rowPins[ROWS] = {25,24,23,22};
byte colPins[COLS] = {29,28,27,26};
LiquidCrystal lcd(49,48,47,43,42,41);
boolean rightOrNot = false;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);
int index=0;
char correct[4] = {'1','2','3','4'};
char ans[4] = {'0','0','0','0'};
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("KEY IN: ");
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  char customKey  = customKeypad.getKey();
  if(customKey){
    ans[index] = customKey;
    Serial.println(customKey);
    Serial.println(index);
    Serial.println(ans[index]);
    ++index;
  }
  if(index==4){
    for(int i=0;i<4;i++){
        Serial.println("Index == 4");
        lcd.setCursor(7+i,0);
        lcd.print(ans[i]);
        Serial.println(ans[i]);
    }
    for(int i=0;i<4;i++){
        if(correct[i]==ans[i]){
            rightOrNot = true;
        }else{
            rightOrNot = false;
            break;
        }
    }
    lcd.setCursor(0,1);
    if(rightOrNot){    
        lcd.print("good");
    }
    else{
        lcd.print("bad");
    }
    index=0;
  }
}

