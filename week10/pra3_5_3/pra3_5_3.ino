#define CA1 30
#define CA2 31
#define CA3 32
//ex3-5-4
#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
#include<Stepper.h>
#include <Keypad.h>
Stepper stepper(200,A,A_BAR,B,B_BAR);

int redPin = 44;
int grnPin = 45;
int bluPin = 46;
int speed = 10;

int delay_time = 4;

//2-8
int BASE = 6;
int NUM = 4;
int BASE1 = 33;
int beforeK1state=1;
int beforeK2state=1;
int beforeK3state=1;
int beforeK4state=1;
int K1state=1;
int K2state=1;
int K3state=1;
int K4state=1;
int ans[5]={0};
int ro_flag = 0; // 0 正轉 1 反轉
int ro_times = 0; // 轉多少次

// ex2-9
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
                              {0,0,0,0},
                              {0,3,6,9},
                              {0,2,5,8},                                                
                              {0,1,4,7}};
byte rowPins[ROWS]={25,24,23,22};
byte colPins[ROWS]={29,28,27,26};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);


void setup() {
  // put your setup code here, to run once:
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
  stepper.setSpeed(50);
  Serial.begin(9600);
  for(int i=BASE1;i<BASE1+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }  
}


void loop() {
  // put your main code here, to run repeatedly: 
  char customKey = customKeypad.getKey();
  if(customKey){
    Serial.println(customKey);
    ro_times = customKey;
  }
  
   Serial.print("Flag: ");
   Serial.println(ro_flag);
   Serial.print("Times: ");
   Serial.println(ro_times);
   K1state = digitalRead(33);
  if(K1state==0 and beforeK1state==1){
    ro_flag = 0;
  }
  beforeK1state = K1state;
  K2state = digitalRead(34);
  if(K2state==0 and beforeK2state==1){
    ro_flag = 1;
  }
  beforeK2state = K2state;
   for(int i=0;i<ro_times;i++){
     if(ro_flag==0){
       analogWrite(redPin,255);
        analogWrite(grnPin,0);
        analogWrite(bluPin,255);
       unsigned long startTime = millis();
       for(int i=ro_times;i>0;i--){
         for(unsigned long elapsed = 0;elapsed<150;elapsed = millis() - startTime){
              //ex2-7
              //往上推是0;往下推是1
              pickDigit(4);
              pickNumber(ro_times);
              delay(1000);
          }
        }
        pickDigit(4);
        pickNumber(ro_times);
        stepper.step(2000);
     }else if(ro_flag==1){
        analogWrite(redPin,0);
        analogWrite(grnPin,255);
        analogWrite(bluPin,255);
        unsigned long startTime = millis();
       for(unsigned long elapsed = 0;elapsed<150;elapsed = millis() - startTime){
            //ex2-7
            //往上推是0;往下推是1
            pickDigit(4);
            pickNumber(ro_times);
            
        }
        pickDigit(4);
        pickNumber(ro_times);
        stepper.step(-2000);
     }
  }
  ro_times = 0;
}

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

