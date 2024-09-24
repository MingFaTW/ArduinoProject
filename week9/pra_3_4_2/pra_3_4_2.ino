//ex2-12-1
#include <LiquidCrystal.h>
LiquidCrystal lcd(49,48,47,43,42,41);

//ex3-4-2
const int motorIn1 = 2;
const int motorIn2 = 3;
const int tt = 100;

int BASE = 6;
int NUM = 4;
int BASE1 = 33;
int K1state;
int K2state;
int K3state;
int K4state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("The Value: ");
  lcd.setCursor(0,1);
  //ex2-8
  for(int i=BASE;i<BASE+NUM;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=BASE1;i<BASE1+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }
  
  int i;
  digitalWrite(motorIn2,LOW);
  /*
  for(i=100;i<=255;i+=10){
    analogWrite(motorIn1,i);
    delay(tt);
  }
  for(i=255;i>=100;i-=10){
    analogWrite(motorIn1,i);
    delay(tt);
  }*/
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  K1state = digitalRead(33);
  K2state = digitalRead(34);
  K3state = digitalRead(35);
  K4state = digitalRead(36);
  digitalWrite(9,K1state);
  digitalWrite(8,K2state);
  digitalWrite(7,K3state);
  digitalWrite(6,K4state);
  Serial.println(K1state);
  Serial.println(K2state);
  Serial.println(K3state);
  Serial.println(K4state);

  if(K1state==0){
    analogWrite(motorIn1,0);
    lcd.setCursor(0,11);
    lcd.print("0");
    delay(tt);
  }
  if(K2state==0){
    analogWrite(motorIn1,150);
    lcd.setCursor(0,11);
    lcd.print("1");
    delay(tt);
  }
  if(K3state==0){
    analogWrite(motorIn1,200);
    lcd.setCursor(0,11);
    lcd.print("2");
    delay(tt);
  }
  if(K4state==0){
    analogWrite(motorIn1,255);
    lcd.setCursor(0,11);
    lcd.print("3");
    delay(tt);
  }
  
}
