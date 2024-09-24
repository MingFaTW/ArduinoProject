//2-4-2
#define CA1 30
#define CA2 31
#define CA3 32
int delay_time = 4;

//ex2-7
int BASE_DIPSW=37;
int beforeDIPSW1state=1;
int beforeDIPSW2state=1;
int beforeDIPSW3state=1;
int beforeDIPSW4state=1;
int DIPSW1state=1;
int DIPSW2state=1;
int DIPSW3state=1;
int DIPSW4state=1;

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

void setup() {
  //ex2-7
  ans[1]=1;
  ans[2]=1;
  ans[3]=1;
  ans[4]=1;
  for(int i=BASE;i<BASE+NUM;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=BASE_DIPSW;i<BASE_DIPSW+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }   
  //2-8
  // put your setup code here, to run once:
  for(int i=BASE;i<BASE+NUM;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=BASE1;i<BASE1+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }  
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
  
  Serial.begin(9600); 
  Serial.println(K1state);
  //2-4-2
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
  
}


void loop() {
  
  for(unsigned int number = 0;number<1000;number++){
    unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed<300;elapsed = millis() - startTime){
      //ex2-7
      //往上推是0;往下推是1
      DIPSW1state = digitalRead(37);  
      DIPSW2state = digitalRead(38);
      DIPSW3state = digitalRead(39);
      DIPSW4state = digitalRead(40);
      K1state = digitalRead(33);
      if(K1state==0 and beforeK1state==1){
        if(DIPSW4state==0){
              ++ans[4];
              if(ans[4]>15){
                ans[4]=0;
                ans[3]=0;
                ans[2]=0;
                ans[1]=0;
              }
          }
          else{
                if(ans[4]>=0)
                  --ans[4];
                if(ans[4]<0){
                  ans[4]=0;
                  --ans[3];
                }
                if(ans[3]<0){
                  ans[3]=0;
                  --ans[2];
                }
                if(ans[2]<0){
                  ans[2]=0;
                  --ans[1];
                }
          }
      }
      beforeK1state = K1state;
      K2state = digitalRead(34);
      if(K2state==0 and beforeK2state==1){
        if(DIPSW3state==0){
              ++ans[3];
              if(ans[1]>15){
                ans[1]=0;
                ++ans[2];
              }
              if(ans[2]>15){
                ans[2]=0;
                ++ans[3];
              }
              if(ans[3]>15){
                ans[3]=0;
                ++ans[4];
              }
              if(ans[4]>15){
                ans[4]=0;
                ans[3]=0;
                ans[2]=0;
                ans[1]=0;
              }
           }
        
          else{
                if(ans[3]>=0)
                  --ans[3];
                if(ans[3]<0){
                  ans[3]=0;
                  --ans[2];
                }
                if(ans[2]<0){
                  ans[2]=0;
                  --ans[1];
                }
          }
      }
      beforeK2state = K2state;
      K3state = digitalRead(35);
      if(K3state==0 and beforeK3state==1){
        if(DIPSW2state==0){
              ++ans[2];
              if(ans[1]>15){
                ans[1]=0;
                ++ans[2];
              }
              if(ans[2]>15){
                ans[2]=0;
                ++ans[3];
              }
              if(ans[3]>15){
                ans[3]=0;
                ++ans[4];
              }
              if(ans[4]>15){
                ans[4]=0;
                ans[3]=0;
                ans[2]=0;
                ans[1]=0;
              }
           }
          else{
                if(ans[2]>=0)
                  --ans[2];
                if(ans[2]<0){
                  ans[2]=0;
                  --ans[1];
                }
          }
      }
        beforeK3state = K3state;
        //beforeDIPSW2state = DIPSW2state;
        K4state = digitalRead(36);
        if(K4state==0 and beforeK4state==1){
        if(DIPSW1state==0){
              ++ans[1];
              if(ans[1]>15){
                ans[1]=0;
                ++ans[2];
              }
              if(ans[2]>15){
                ans[2]=0;
                ++ans[3];
              }
              if(ans[3]>15){
                ans[3]=0;
                ++ans[4];
              }
              if(ans[4]>15){
                ans[4]=0;
                ans[3]=0;
                ans[2]=0;
                ans[1]=0;
              }
           }
          else{
                --ans[1];
          }
      }
        beforeK4state = K4state;
        //beforeDIPSW1state = DIPSW1state;
        pickDigit(4);
        pickNumber(ans[4]);
        delay(delay_time);
        pickDigit(3);
        pickNumber(ans[3]);
        delay(delay_time);
        pickDigit(2);
        pickNumber(ans[2]);
        delay(delay_time);
        pickDigit(1);
        pickNumber(ans[1]);
        delay(delay_time);
      }
  }
}


  //2-4-2
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
    case 0:
      zero();break;
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
    case 10:
      ten();break;
    case 11:
      eleven();break;
    case 12:
      twelve();break;
    case 13:
      thirteen();break;
    case 14:
      fourteen();break;
    case 15:
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
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void ten(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void eleven(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void twelve(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void thirteen(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void fourteen(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void fifteen (){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

