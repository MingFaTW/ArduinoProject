//ex2-9
#include <Keypad.h>

#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
#include<Stepper.h>
//pra_week301
#define CA1 30
#define CA2 31
#define CA3 32

Stepper stepper(200,A,A_BAR,B,B_BAR);
//pra_week301
int redPin = 44;
int grnPin = 45;
int bluPin = 46;
int speed = 10;

int BASE = 6;
int NUM = 4;
int BASE1 = 33;
int K1state;
int K2state;
int K3state;
int K4state;

//ex2-9
int delay_time = 4;
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
                              {'F','E','D','C'},
                              {'B','3','6','9'},
                              {'A','2','5','8'},                                                
                              {'0','1','4','7'}};
byte rowPins[ROWS]={25,24,23,22};
byte colPins[ROWS]={29,28,27,26};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);
char answer[4];
int answerNum=0;


// circle 
int circles = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(50);
  //pra_week_301
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(CA1,OUTPUT);
  pinMode(CA2,OUTPUT);
  pinMode(CA3,OUTPUT);
  pinMode(A13,OUTPUT);
  digitalWrite(A13,LOW);
  
  pinMode(redPin,OUTPUT);
  pinMode(grnPin,OUTPUT);
  pinMode(bluPin,OUTPUT);
  analogWrite(redPin, 255);
  analogWrite(grnPin, 255);
  analogWrite(bluPin, 255);
  for(int i=BASE1;i<BASE1+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(unsigned int number = 60;number>0;number--){
    analogWrite(grnPin,0);
    unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed<150;elapsed = millis() - startTime){
          pickDigit(1);
          pickNumber(circle/1000);
          pickDigit(2);
          pickNumber(circle/100%10);
          pickDigit(3);
          pickNumber(circle%100);
          delay(delay_time);
          pickDigit(4);
          pickNumber();
          delay(delay_time);  
      }
   }
  
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
    stepper.step(2000);
    analogWrite(redPin,255);
    analogWrite(grnPin,0);
    analogWrite(bluPin,255);
    delay(tt);
  }
  if(K2state==0){
    stepper.step(-2000);
    analogWrite(redPin, 0);
    analogWrite(grnPin, 255);
    analogWrite(bluPin, 255);
    delay(tt);
  }
  if(K3state==0){
    stepper.step(50);
    delay(tt);
  }
  if(K4state==0){
    stepper.step(50);
    delay(tt);
  }
}

// pra_week301
void pickDigit(int x){
  digitalWrite(CA1,HIGH);
  digitalWrite(CA2,HIGH);
  digitalWrite(CA3,HIGH);
  switch(x){
    case 1:
      digitalWrite(CA1,LOW);
      digitalWrite(CA2,LOW);
      digitalWrite(CA3,LOW);
      break;
    case 2:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,LOW);
      digitalWrite(CA3,LOW);
      break;
    case 3:
      digitalWrite(CA1,LOW);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW);
      break;
    case 4:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW);
      break;
  }
}

void pickNumber(int x){
  switch(x){
    case 1:
      one();break;
    case 2:
      two();break;
    case 3:
      three();break;
    case 4:
      four();break;
    case 5:
      five();break;
    case 6:
      six();break;
    case 7:
      seven();break;
    case 8:
      eight();break;
    case 9:
      nine();break;
    case 10: //A
      ten();break;
    case 11: //B
      eleven();break;
    case 12: //C
      twelve();break;
    case 13: //D
      thirteen();break;
    case 14: //E
      fourteen();break;
    case 15: //F
      fifteen();break;
    default:
      zero();break;
  }
}

void zero(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void one(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void two(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}

void three(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void four(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void five(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void six(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void seven(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void eight(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void nine(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void ten(){ //A
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void eleven(){ //B
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void twelve(){ //C
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}
void thirteen(){ //D
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void fourteen(){ //E
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void fifteen(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
