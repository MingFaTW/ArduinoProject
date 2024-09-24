//morseCode design
#include <LiquidCrystal.h>
LiquidCrystal lcd(49,48,47,43,42,41);
//2-4-2
int delay_time = 4;
int BUZZER = A9;
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

char secret[100]={};

char temp[100][5]={}; 
char ans[30]={};
int i = 0;
int tempIndex = 0;
int tempCount = 0;
boolean cout = false;

char c_A[5] = {'.','-'};
char c_B[5] = {'-','.','.','.'};
char c_C[5] = {'-','.','-','.'};
char c_D[5] = {'-','.','.'};
char c_E[5] = {'.'};
char c_F[5] = {'.','.','-','.'};
char c_G[5] = {'-','-','.'};
char c_H[5] = {'.','.','.','.'};
char c_I[5] = {'.','.'};
char c_J[5] = {'.','-','-','-'};
char c_K[5] = {'-','.','-'};
char c_L[5] = {'.','-','.','.'};
char c_M[5] = {'-','-'};
char c_N[5] = {'-','.'};
char c_O[5] = {'-','-','-'};
char c_P[5] = {'.','-','-','.'};
char c_Q[5] = {'-','-','.','-'};
char c_R[5] = {'.','-','.'};
char c_S[5] = {'.','.','.'};
char c_T[5] = {'-'};
char c_U[5] = {'.','.','-'};
char c_V[5] = {'.','.','.','-'};
char c_W[5] = {'.','-','-'};
char c_X[5] = {'-','.','.','-'};
char c_Y[5] = {'-','.','-','-'};
char c_Z[5] = {'-','-','.','.'};
void setup() {
  //ex2-7
  lcd.begin(16,2);
  lcd.setCursor(0,0);
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
  pinMode(BUZZER,OUTPUT);
  digitalWrite(A15,LOW);
  
  Serial.begin(9600); 
  Serial.println(K1state);
  
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(A13,LOW);
  Serial.begin(9600);

}


void loop() {

  for(unsigned int number = 0;number<1000;number++){
    unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed<300;elapsed = millis() - startTime){
      if(i>=16)
        lcd.setCursor(i-16,1);
      //ex2-7
      DIPSW1state = digitalRead(37);  
      DIPSW2state = digitalRead(38);
      DIPSW3state = digitalRead(39);
      DIPSW4state = digitalRead(40);
      K1state = digitalRead(33);
      if(K1state==0 and beforeK1state==1){
        if(DIPSW4state==0){
                  Serial.print(".");
                  secret[i++] = '.';
                  digitalWrite(BUZZER,HIGH);
                  lcd.print('.');
                  delay(10);
              }
          
          else{
                  cout = true;
                  if(cout==true){
                    Serial.println();
                    Serial.println("Cipher Text: ");
                    for(int index=0;index<i;index++){
                      Serial.print(secret[index]);
                    }
                  }
                  cout = false;
               }
          
      }
      beforeK1state = K1state;
      K2state = digitalRead(34);
      if(K2state==0 and beforeK2state==1){
        if(DIPSW3state==0){
                 Serial.print("-");
                 secret[i++] = '-';

                 lcd.print('-');
                 digitalWrite(BUZZER,HIGH);
                 delay(10);
           }
          else{
            
                cout = true;
                  if(cout==true){
                    for(int index=0;index<i;index++){
                      if(secret[index]!=' '){
                         temp[tempIndex][tempCount++]=secret[index];
                      }
                      else{
                         tempIndex = tempIndex+1;
                         tempCount = 0;
                      }
                    }
                    
                    boolean tempFlag = false;
                    int allRight = 0;
                    int ansCount = 0;
              
                    Serial.println();
                    Serial.println("Plain text: ");
                    for(int index=0;index<tempIndex+1;index++){
                        //A
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_A[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'A';
                          ansCount = ansCount + 1;
                        }
                        
                        //B
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_B[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'B';
                          ansCount = ansCount + 1;
                        }
                        //C
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_C[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'C';
                          ansCount = ansCount + 1;
                        }
                        //D
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_D[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'D';
                          ansCount = ansCount + 1;
                        }
                        //E
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_E[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'E';
                          ansCount = ansCount + 1;
                        }
                        //F
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_F[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'F';
                          ansCount = ansCount + 1;
                        }
                        //G
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_G[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'G';
                          ansCount = ansCount + 1;
                        }
                        //H
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_H[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'H';
                          ansCount = ansCount + 1;
                        }
                        //I
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_I[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'I';
                          ansCount = ansCount + 1;
                        }
                        //J
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_J[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'J';
                          ansCount = ansCount + 1;
                        }
                        //K
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_K[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'K';
                          ansCount = ansCount + 1;
                        }
                        //L
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_L[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'L';
                          ansCount = ansCount + 1;
                        }
                        //M
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_M[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'M';
                          ansCount = ansCount + 1;
                        }
                        //N
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_N[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'N';
                          ansCount = ansCount + 1;
                        }
                        //O
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_O[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'O';
                          ansCount = ansCount + 1;
                        }
                        //P
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_P[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'P';
                          ansCount = ansCount + 1;
                        }
                        //Q
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_Q[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'Q';
                          ansCount = ansCount + 1;
                        }
                        //R
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_R[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'R';
                          ansCount = ansCount + 1;
                        }
                        //S
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_S[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'S';
                          ansCount = ansCount + 1;
                        }
                        //T
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_T[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'T';
                          ansCount = ansCount + 1;
                        }
                        //U
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_U[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'U';
                          ansCount = ansCount + 1;
                        }
                        //V
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_V[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'V';
                          ansCount = ansCount + 1;
                        }
                        //W
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_W[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'W';
                          ansCount = ansCount + 1;
                        }
                        //X
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_X[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'X';
                          ansCount = ansCount + 1;
                        }
                        //Y
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_Y[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'Y';
                          ansCount = ansCount + 1;
                        }
                        //Z
                        for(int jndex=0;jndex<5;jndex++){
                          if(temp[index][jndex]==c_Z[jndex]){
                            tempFlag = true;
                          }
                          else{
                            tempFlag = false;
                            break;
                          }
                        }
                        if(tempFlag == true){
                          ans[ansCount] = 'Z';
                          ansCount = ansCount + 1;
                        }
                    }
                    lcd.clear();
                    lcd.setCursor(0,0);
                    lcd.print("The PlainText: ");
                    lcd.setCursor(0,1);
                    for(int kndex=0;kndex<ansCount;kndex++){
                      Serial.print(ans[kndex]);
                      lcd.print(ans[kndex]);
                    }
                  }
                cout = false;
                tempCount = 0;
                
                for(int index=0;index<tempIndex;i++){
                  for(int jndex=0;jndex<5;jndex++){
                    temp[index][jndex] = ' ';
                  }
                }
          }
      }
      beforeK2state = K2state;
      K3state = digitalRead(35);
      if(K3state==0 and beforeK3state==1){
        if(DIPSW2state==0){
              Serial.print(" ");
              secret[i++] = ' ';
              lcd.print(' ');
           }
          else{
                
           }
       }
        beforeK3state = K3state;
        //beforeDIPSW2state = DIPSW2state;
        K4state = digitalRead(36);
        if(K4state==0 and beforeK4state==1){
        if(DIPSW1state==0){
          //reset the matrix and intial values.
              Serial.println("Recover to initial states");
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Recover to");
              lcd.setCursor(0,1);
              lcd.print("initial states");
              delay(2000);
              lcd.clear();
              lcd.setCursor(0,0);
              for(int i=0; i<100; i++){
                secret[i]=' ';
                ans[i]=' ';
                for(int j=0; j<5; j++){
                  temp[i][j]=' ';
                }
              }
              i = 0;
              tempIndex = 0;
              tempCount = 0;
              cout = false;
           }
          else{
                
          }
      }
      beforeK4state = K4state;
      delay(delay_time);
    }
      digitalWrite(BUZZER,LOW);
  }
}


