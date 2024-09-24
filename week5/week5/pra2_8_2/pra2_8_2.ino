//pra2_6_3
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


#define data_1 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,1,1,0,\
                0,0,1,1,1,0,0,1,\
                0,1,0,0,1,0,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,1,0,0,0,1,0,\
                0,1,1,0,0,0,0,1}

#define data_2 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,1,1,0,\
                0,0,1,1,1,0,1,1,\
                0,1,1,0,1,0,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,1,0,0,0,1,0,\
                0,1,1,0,0,0,0,1}

#define data_3 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,1,1,0,1,0,\
                0,0,1,0,1,0,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,0,1,0}

#define data_4 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,1,0,0,1,0,0,\
                0,0,1,0,0,0,1,0}

#define data_5 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,1,1,0,1,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,0,1,1,0,0,\
                0,0,0,0,1,1,0,0,\
                0,0,0,0,0,1,0,0}

#define data_6 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,1,1,1,0,0,0,\
                0,0,0,0,1,1,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,0,1,0,0,1,0}

#define data_7 {0,0,1,1,1,0,0,0,\
                0,0,1,1,0,0,0,0,\
                0,0,0,1,1,1,0,0,\
                0,0,1,1,1,0,1,0,\
                0,1,0,1,1,0,0,0,\
                0,0,0,0,1,0,0,0,\
                0,0,0,1,0,1,0,0,\
                0,0,1,0,0,0,1,0}

#define data_Stop {0,0,0,1,1,1,0,0,\
                   0,0,0,1,1,1,0,0,\
                   0,0,0,0,1,0,0,0,\
                   0,0,1,1,1,1,1,0,\
                   0,1,0,0,1,0,0,1,\
                   0,0,0,0,1,0,0,0,\
                   0,0,0,1,0,1,0,0,\
                   0,0,1,0,0,0,1,0}
//btnclicker
int pushButton = 33;
int buttonState = 0;
int beforeState = 0;
int pressTime = 1;

//ex2_5_1
int redPin = 44;
int grnPin = 45;
int bluPin = 46;
int speed = 1000;
int yellowSpeed = 500;
int colorState=1; // grn=1 yew=2 red=3

//pra2-6-3
boolean word_array1[4][row_size][col_size]={data_1};
boolean word_array2[4][row_size][col_size]={data_2};
boolean word_array3[4][row_size][col_size]={data_3};
boolean word_array4[4][row_size][col_size]={data_4};
boolean word_array5[4][row_size][col_size]={data_5};
boolean word_array6[4][row_size][col_size]={data_6};
boolean word_array7[4][row_size][col_size]={data_7};
boolean word_arrayStop[4][row_size][col_size]={data_Stop};

boolean led[row_size][col_size];
byte row_pin[row_size] = {R0,R1,R2,R3,R4,R5,R6,R7};

void setup() {
  // put your setup code here, to run once:
    //btnclicker
    Serial.begin(9600);
    pinMode(pushButton,INPUT_PULLUP);
    //ex2-5-1
    pinMode(redPin,OUTPUT);
    pinMode(grnPin,OUTPUT);
    pinMode(bluPin,OUTPUT);
    //pra2-6-3
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
   
  //pra2-6-3
  if((colorState==1)||(colorState==2)){
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
  }
  else if(colorState==3){
    word_to_ledStop(0);
    display_led(led,1000);
  }
}

//pra2-6-3
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

void word_to_ledStop(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayStop[n][i][j];
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
        if(led[j][i] == 1){
          digitalWrite(row_pin[j],HIGH);
          //btnclicker
          buttonState = digitalRead(pushButton);
          if(buttonState==1 and beforeState==0){
                Serial.println(colorState);
                colorState=colorState+1;
                if(colorState>3){
                    colorState=1;
                }
          }
          beforeState = buttonState;
          if(colorState==1){
            analogWrite(redPin,255);
            analogWrite(grnPin,0);
            analogWrite(bluPin,255);
          }
          if(colorState==2){
            analogWrite(redPin,0);
            analogWrite(grnPin,0);
            analogWrite(bluPin,255);
          }
          if(colorState==3){
            analogWrite(redPin,0);
            analogWrite(grnPin,255);
            analogWrite(bluPin,255);
            
          }
        }
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
