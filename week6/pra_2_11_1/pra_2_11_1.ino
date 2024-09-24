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
//2-11
#define row_size 8
#define col_size 8
#define delay_time 300
const byte ROWS = 4;
const byte COLS = 4;

int joyPinX=A1;
int joyPinY=A2;
int SW=A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;

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
                 
#define data_left{0,0,0,0,0,0,0,0,\
                 0,0,1,1,0,0,0,0,\
                 0,1,1,0,0,0,0,0,\
                 0,1,1,1,1,1,1,0,\
                 0,1,1,1,1,1,1,0,\
                 0,1,1,0,0,0,0,0,\
                 0,0,1,1,0,0,0,0,\
                 0,0,0,0,0,0,0,0}

#define data_right{0,0,0,0,0,0,0,0,\
                 0,0,0,0,1,1,0,0,\
                 0,0,0,0,0,1,1,0,\
                 0,1,1,1,1,1,1,0,\
                 0,1,1,1,1,1,1,0,\
                 0,0,0,0,0,1,1,0,\
                 0,0,0,0,1,1,0,0,\
                 0,0,0,0,0,0,0,0}

#define data_up_right{0,0,0,0,0,0,0,0,\
                      0,0,0,1,1,1,1,1,\
                      0,0,0,0,0,1,1,1,\
                      0,0,0,0,1,1,0,1,\
                      0,0,0,1,1,0,0,1,\
                      0,0,1,1,0,0,0,0,\
                      0,1,1,0,0,0,0,0,\
                      0,0,0,0,0,0,0,0}
                      
#define data_right_down{0,0,0,0,0,0,0,0,\
                        0,1,1,0,0,0,0,0,\
                        0,0,1,1,0,0,0,0,\
                        0,0,0,1,1,0,0,1,\
                        0,0,1,0,1,1,0,1,\
                        0,0,0,1,0,1,1,1,\
                        0,0,0,0,1,1,1,0,\
                        0,0,0,0,0,0,0,0}
                      
#define data_down_left{0,0,0,0,0,0,0,0,\
                      0,0,0,0,0,0,1,1,\
                      0,0,0,0,0,1,1,0,\
                      0,1,0,0,1,1,0,0,\
                      0,1,0,1,1,0,0,0,\
                      0,1,1,1,0,0,0,0,\
                      0,1,1,1,1,1,0,0,\
                      0,0,0,0,0,0,0,0}
                      
#define data_left_up{0,0,0,0,0,0,0,0,\
                     0,1,1,1,1,1,0,0,\
                     0,1,1,1,0,0,0,0,\
                     0,1,0,1,1,0,0,0,\
                     0,1,0,0,1,1,0,0,\
                     0,0,0,0,0,1,1,0,\
                     0,0,0,0,0,0,1,1,\
                     0,0,0,0,0,0,0,0}
boolean word_arrayUp[4][row_size][col_size]={data_up};
boolean word_arrayDown[4][row_size][col_size]={data_down};
boolean word_arrayLeft[4][row_size][col_size]={data_left};
boolean word_arrayRight[4][row_size][col_size]={data_right};

boolean word_arrayUp_right[4][row_size][col_size]={data_up_right};
boolean word_arrayRight_down[4][row_size][col_size]={data_right_down};
boolean word_arrayDown_left[4][row_size][col_size]={data_down_left};
boolean word_arrayLeft_up[4][row_size][col_size]={data_left_up};

boolean led[row_size][col_size];
byte row_pin[row_size] = {R0,R1,R2,R3,R4,R5,R6,R7};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
  
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
}

void loop() {
  // put your main code here, to run repeatedly: 
  int x,y,value;
  value = analogRead(joyPinX);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  SWstate = digitalRead(SW);
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("  Y = ");
  Serial.print(y);
  Serial.print("SW = ");
  Serial.println(SWstate);
  delay(10);
  if((abs(x)<2)&&(abs(y)<2)){
    
  }
  else if((abs(x)<150)&&(y<25)){
      word_to_ledRight(0);
      display_led(led,1000);
      Serial.println("Right");
  }else if((x>25)&&(abs(y)<150)){
      word_to_ledDown(0);
      display_led(led,1000);
      Serial.println("Down");
  }else if((abs(x)<=150)&&(y>=150)){
      word_to_ledLeft(0);
      display_led(led,1000);
      Serial.println("Left");
  }else if((x<-400)&&((abs(y)<150))){
      word_to_ledUp(0);
      display_led(led,1000);
      Serial.println("Up");
  }else if((x<-250)&&((y<-250))){
      word_to_ledUp_right(0);
      display_led(led,1000);
      Serial.println("Up_right");
  }else if((x>250)&&((y<-250))){
      word_to_ledRight_down(0);
      display_led(led,1000);
      Serial.println("Right_down");
  }else if((x>250)&&((y>250))){
      word_to_ledDown_left(0);
      display_led(led,1000);
      Serial.println("Down_left");
  }else if((x<250)&&((y>250))){
      word_to_ledLeft_up(0);
      display_led(led,1000);
      Serial.println("Left_up");
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

void word_to_ledLeft(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayLeft[n][i][j];
}

void word_to_ledRight(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayRight[n][i][j];
}

void word_to_ledUp_right(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayUp_right[n][i][j];
}

void word_to_ledRight_down(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayRight_down[n][i][j];
}

void word_to_ledDown_left(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayDown_left[n][i][j];
}

void word_to_ledLeft_up(int n){
  for(int i=0;i<row_size;i++)
    for(int j=0;j<col_size;j++)
      led[i][j] = word_arrayLeft_up[n][i][j];
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

