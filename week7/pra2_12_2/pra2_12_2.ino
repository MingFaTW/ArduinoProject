//ex2-11-2
#include <LiquidCrystal.h>
int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;
LiquidCrystal lcd(49,48,47,43,42,41);
char MAGA[4] = {'M','A','G','A'}; 
int w=0,h=0;
char ans[2][16] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                   {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
int pos[2] = {0,0}; //width 15-4=11 0~11; height=0~1
void setup() {
  // put your setup code here, to run once:
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int x,y,value;
  
  /*
  for(int i=0;i<4;i++){
    lcd.setCursor(0+i,0);
    lcd.print(MAGA[i]);
  }*/
  lcd.setCursor(0,1);
  //lcd.print("SW= ");
  value = analogRead(joyPinX);
  //Serial.println("value: "+x);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  SWstate = digitalRead(SW);
  //Serial.println("x: "+x);
  //Serial.println("y: "+y);
  //pra-2-11-1
  if((abs(x)<2)&&(abs(y)<2)){
     
  }
  else if((abs(x)<150)&&(y<25)){
      if(w<12)
        ++w;
      Serial.println("Right");
  }else if((x>25)&&(abs(y)<150)){
      if(h==0)
        ++h;
      Serial.println("Down");
  }else if((abs(x)<=150)&&(y>=150)){
      if(w>1)
        --w;
      Serial.println("Left");
  }else if((x<-400)&&((abs(y)<150))){
      if(h==1)
        --h;
      Serial.println("Up");
  }
  clearLcdPrint();
  lcd.setCursor(w,h);
  lcd.print("MAGA");
  delay(30);
}

void clearLcdPrint(){
  for(int i=0;i<16;i++){
    lcd.setCursor(i,0);
    lcd.print(" ");
  }
  for(int i=0;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }
}

