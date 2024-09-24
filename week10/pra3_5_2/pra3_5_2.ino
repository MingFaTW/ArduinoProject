//ex3-5-4
#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
#include<Stepper.h>
#include <LiquidCrystal.h>
// pra2-6-1
#define Ls138_A 30
#define Ls138_B 31
#define Ls138_C 32
#define R0 2
#define R1 3
#define R2 4
#define R3 5
#define R4 6
#define R5 7
#define R6 8
#define R7 9

#define row_size 8
#define col_size 8
#define delay_time 300
// pra2-11-1
#define data_up{0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,1,1,1,1,1,1,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_down{0,0,0,0,0,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,1,1,1,0,0,\
                 0,1,1,1,1,1,1,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0}
Stepper stepper(200,A,A_BAR,B,B_BAR);

//ex2-11-2

int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;
LiquidCrystal lcd(49,48,47,43,42,41);


boolean word_arrayUp[4][row_size][col_size]={data_up};
boolean word_arrayDown[4][row_size][col_size]={data_down};

boolean led[row_size][col_size];
byte row_pin[row_size] = {R0,R1,R2,R3,R4,R5,R6,R7};

void setup() {
  // put your setup code here, to run once:
  //ex2-11-2
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
  lcd.begin(16,2);
  Serial.begin(9600);
  stepper.setSpeed(50);
  //pra2-11-1
  pinMode(Ls138_A,OUTPUT);
  pinMode(Ls138_B,OUTPUT);
  pinMode(Ls138_C,OUTPUT);
  pinMode(R0,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(R6,OUTPUT);
  pinMode(R7,OUTPUT);
  clear_led();
  pinMode(A14,OUTPUT);
  digitalWrite(A14,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  //stepper.step(200);
  //stepper.step(-200);
  //ex2-11-2
  int x,y,value;
  value = analogRead(joyPinX);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  if((abs(x)<2)&&(abs(y)<2)){
      Serial.println("Stop");
      stepper.step(0);
  }
  else if((x<-400)&&((abs(y)<150))){
    
    Serial.println("Up");  
    word_to_ledUp(0);
    display_led(led,1000);
    stepper.step(50);
  }else if((x>25)&&(abs(y)<150)){
    
    Serial.println("Down");
    word_to_ledDown(0);
    display_led(led,1000);  
    stepper.step(-50);
  }
}

void word_to_ledUp(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayUp[n][i][j];
}
void word_to_ledDown(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayDown[n][i][j];
}
void clear_led(){
  for(int i=0;i<row_size;i++)
    digitalWrite(row_pin[i],LOW);
}

void display_led(byte led[row_size][col_size],int continue_time){
  for(int k=0;k<continue_time;k++){
    for(int i=0;i<col_size;i++){
      clear_led();
      low_74138pin(i);
      for(int j=0;j<row_size;j++)
        if(led[j][i] == 1)
          digitalWrite(row_pin[j],HIGH);
    }
  }
}

void low_74138pin(int num){
  switch(num){
    case 0:
      digitalWrite(Ls138_A,LOW);
      digitalWrite(Ls138_B,LOW);
      digitalWrite(Ls138_C,LOW);
      break;
    case 1:
      digitalWrite(Ls138_A,HIGH);
      digitalWrite(Ls138_B,LOW);
      digitalWrite(Ls138_C,LOW);
      break;
    case 2:
      digitalWrite(Ls138_A,LOW);
      digitalWrite(Ls138_B,HIGH);
      digitalWrite(Ls138_C,LOW);
      break;
    case 3:
      digitalWrite(Ls138_A,HIGH);
      digitalWrite(Ls138_B,HIGH);
      digitalWrite(Ls138_C,LOW);
      break;
    case 4:
      digitalWrite(Ls138_A,LOW);
      digitalWrite(Ls138_B,LOW);
      digitalWrite(Ls138_C,HIGH);
      break;
    case 5:
      digitalWrite(Ls138_A,HIGH);
      digitalWrite(Ls138_B,LOW);
      digitalWrite(Ls138_C,HIGH);
      break;
    case 6:
      digitalWrite(Ls138_A,LOW);
      digitalWrite(Ls138_B,HIGH);
      digitalWrite(Ls138_C,HIGH);
      break;
    case 7:
      digitalWrite(Ls138_A,HIGH);
      digitalWrite(Ls138_B,HIGH);
      digitalWrite(Ls138_C,HIGH);
      break;
    
  }
}


