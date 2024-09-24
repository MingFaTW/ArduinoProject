#include <LiquidCrystal.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
                              {'0','0','0','0'},
                              {'0','3','6','9'},
                              {'0','2','5','8'},
                              {'0','1','4','7'}};
                              
byte rowPins[ROWS] = {25,24,23,22};
byte colPins[COLS] = {29,28,27,26};
LiquidCrystal lcd(49,48,47,43,42,41);
boolean rightOrNot = false;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);
int index=0;
char correct[4] = {'1','2','3','4'};
char ans[4] = {'0','0','0','0'};
int ans_int[4] = {0};
int ans_sum = 0;
int ans_max = 4095;
int ans_binary[12] = {0};

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
    if(index<=3){
        ans[index] = customKey;
        ans_int[index] = customKey-48;
        lcd.setCursor(7+index,0);
        lcd.print(ans[index]);
    }
    Serial.println(ans[index]);
    if(index==0){
        lcd.setCursor(0,1);
        ans_sum = ans_int[0];
        index++;
    }else if(index==1){
        lcd.setCursor(0,1);
        ans_sum = ans_int[0]*10 + ans_int[1];
        index++;        
    }else if(index==2){
        lcd.setCursor(0,1);
        ans_sum = ans_int[0]*100+ans_int[1]*10 + ans_int[2];
        index++;        
    }else if(index==3){
        lcd.setCursor(0,1);
        ans_sum = ans_int[0]*1000+ans_int[1]*100+ans_int[2]*10 + ans_int[3];
        index++;       
    }
    else if(index>3){
        for(int i=0;i<4;i++){
            lcd.setCursor(7+i,0);
            lcd.print(" ");
        }
        for(int i=0;i<16;i++){
            lcd.setCursor(0+i,1);
            lcd.print(" ");
        }
        for(int i=0;i<4;i++){
            ans_int[i]=0;
        }
        for(int i=0;i<4;i++){
            ans[i]='0';
        }
        ans_sum=0;
        index=0; 
    }
    if(ans_sum<4096){
      Serial.println(ans_sum);
      lcd.print(ans_sum,BIN);
    }else{
      lcd.print("OutOfRange");
    }
  }
}


