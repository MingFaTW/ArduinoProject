#include <LiquidCrystal.h>
int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int value = 0;
int xzero = 0;
int yzero = 0;
const int motorIn1 = 2;
const int motorIn2 = 3;
const int tt = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int x,y,value;
  value = analogRead(joyPinX);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  Serial.println(x);
  int i;
  if(x>400){
      forward();
  }
  if(x<-400){
      backward();
  }
  if(x<10){
      motorstop();
  }
  delay(30);
}

void motorstop(){
  digitalWrite(motorIn1,LOW);
  digitalWrite(motorIn2,LOW);
  delay(100);
}

void forward(){
  digitalWrite(motorIn1,HIGH);
  digitalWrite(motorIn2,LOW);
  delay(100);
}

void backward(){
  digitalWrite(motorIn1,LOW);
  digitalWrite(motorIn2,HIGH);
  delay(100);
}
