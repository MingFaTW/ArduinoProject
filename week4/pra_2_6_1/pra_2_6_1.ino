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





#define data_0 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,1,0,\
                 0,0,1,0,0,0,1,0,\
                 0,0,1,0,0,0,1,0,\
                 0,0,1,0,0,0,1,0,\
                 0,0,1,1,1,1,1,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_1 {0,0,0,0,0,0,0,0,\
                 0,0,0,0,1,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,0,1,0,0,0,\
                 0,0,0,0,1,0,0,0,\
                 0,0,1,1,1,1,1,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_2 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_3 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_4 {0,0,0,0,0,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_5 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_6 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_7 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_8 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_9 {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_A {0,0,0,0,0,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,1,0,0,0,0,1,0,\
                 0,0,0,0,0,0,0,0}
#define data_B {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_C {0,0,0,0,0,0,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,0,1,1,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_D {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,0,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,0,0,1,0,0,\
                 0,0,1,1,1,0,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_E {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,0,0,0,0,0,0}
#define data_F {0,0,0,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,1,1,1,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,1,0,0,0,0,0,\
                 0,0,0,0,0,0,0,0}
                 

boolean word_array0[4][row_size][col_size]={data_0};
boolean word_array1[4][row_size][col_size]={data_1};
boolean word_array2[4][row_size][col_size]={data_2};
boolean word_array3[4][row_size][col_size]={data_3};
boolean word_array4[4][row_size][col_size]={data_4};
boolean word_array5[4][row_size][col_size]={data_5};
boolean word_array6[4][row_size][col_size]={data_6};
boolean word_array7[4][row_size][col_size]={data_7};
boolean word_array8[4][row_size][col_size]={data_8};
boolean word_array9[4][row_size][col_size]={data_9};
boolean word_array10[4][row_size][col_size]={data_A};
boolean word_array11[4][row_size][col_size]={data_B};
boolean word_array12[4][row_size][col_size]={data_C};
boolean word_array13[4][row_size][col_size]={data_D};
boolean word_array14[4][row_size][col_size]={data_E};
boolean word_array15[4][row_size][col_size]={data_F};




boolean led[row_size][col_size];
byte row_pin[row_size] = {R0,R1,R2,R3,R4,R5,R6,R7};

void setup() {
  // put your setup code here, to run once:
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
  word_to_led1(0);
  display_led(led,1000);
  word_to_led2(0);
  display_led(led,1000);
  word_to_led3(0);
  display_led(led,1000);
  word_to_led4(0);
  display_led(led,1000);
  word_to_led5(0);
  display_led(led,1000);
  word_to_led6(0);
  display_led(led,1000);
  word_to_led7(0);
  display_led(led,1000);
  word_to_led8(0);
  display_led(led,1000);
  word_to_led9(0);
  display_led(led,1000);
  word_to_led10(0);
  display_led(led,1000);
  word_to_led11(0);
  display_led(led,1000);
  word_to_led12(0);
  display_led(led,1000);
  word_to_led13(0);
  display_led(led,1000);
  word_to_led14(0);
  display_led(led,1000);
  word_to_led15(0);
  display_led(led,1000);
}

void word_to_led0(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array0[n][i][j];
}



void word_to_led1(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array1[n][i][j];
}


void word_to_led2(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array2[n][i][j];
}


void word_to_led3(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array3[n][i][j];
}


void word_to_led4(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array4[n][i][j];
}


void word_to_led5(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array5[n][i][j];
}


void word_to_led6(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array6[n][i][j];
}


void word_to_led7(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array7[n][i][j];
}


void word_to_led8(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array8[n][i][j];
}


void word_to_led9(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array9[n][i][j];
}


void word_to_led10(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array10[n][i][j];
}


void word_to_led11(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array11[n][i][j];
}


void word_to_led12(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array12[n][i][j];
}


void word_to_led13(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array13[n][i][j];
}


void word_to_led14(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array14[n][i][j];
}


void word_to_led15(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_array15[n][i][j];
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











