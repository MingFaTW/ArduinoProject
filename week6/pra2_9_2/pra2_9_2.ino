//ex2-9
#include <Keypad.h>
//pra2_6_1
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

//pra01_01
#define CA1 30
#define CA2 31
#define CA3 32

#define data_O {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,1,0,0,0,0,1,0,\
                 0,1,0,0,0,0,1,0,\
                 0,1,0,0,0,0,1,0,\
                 0,1,0,0,0,0,1,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_X{0,0,0,0,0,0,0,0,\
                 0,0,1,0,0,0,1,0,\
                 0,0,0,1,0,1,0,0,\
                 0,0,0,0,1,0,0,0,\
                 0,0,0,1,0,1,0,0,\
                 0,0,1,0,0,0,1,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
                 
#define data_empty{0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
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

//pra_01_01
boolean word_arrayO[4][row_size][col_size]={data_O};
boolean word_arrayX[4][row_size][col_size]={data_X};
boolean word_arrayEmpty[4][row_size][col_size]={data_empty};
boolean led[row_size][col_size];
byte row_pin[row_size] = {R0,R1,R2,R3,R4,R5,R6,R7};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pra2-6-1
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
  //pra01_01
  
  digitalWrite(9,HIGH);
  pinMode(CA1,OUTPUT);
  pinMode(CA2,OUTPUT);
  pinMode(CA3,OUTPUT);
  pinMode(A13,OUTPUT);
  digitalWrite(A13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  char customKey = customKeypad.getKey();
  if(customKey){
    Serial.println(customKey);
    answer[answerNum] = customKey;
    answerNum++;
  }
    
    unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed<100;elapsed = millis() - startTime){
      pickDigit(4);
      pickNumber(answer[0]);
      delay(delay_time);
      pickDigit(3);
      pickNumber(answer[1]);
      delay(delay_time);  
      pickDigit(2);
      pickNumber(answer[2]);
      delay(delay_time);  
      pickDigit(1);
      pickNumber(answer[3]);
      delay(delay_time); 
      if(answerNum>=4){
          Serial.println(answer);
          if((answer[0]=='1')&&(answer[1]=='4')&&(answer[2]=='5')&&(answer[3]=='0')){
              word_to_ledO(0);
              display_led(led,1000);
          }else{
              word_to_ledX(0);
              display_led(led,1000);
          }
          for(int i=0;i<4;i++){
              answer[i] = '0';
          }
        answerNum=0;
      }
       
    } 
}

void word_to_ledO(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayO[n][i][j];
}

void word_to_ledX(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayX[n][i][j];
}

void word_to_ledEmpty(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayEmpty[n][i][j];
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
//pra_01_01
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

void pickNumber(char x){
  switch(x){
    case '1':
      one();break;
    case '2':
      two();break;
    case '3':
      three();break;
    case '4':
      four();break;
    case '5':
      five();break;
    case '6':
      six();break;
    case '7':
      seven();break;
    case '8':
      eight();break;
    case '9':
      nine();break;
    case 'A': //A
      ten();break;
    case 'B': //B
      eleven();break;
    case 'C': //C
      twelve();break;
    case 'D': //D
      thirteen();break;
    case 'E': //E
      fourteen();break;
    case 'F': //F
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
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
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

