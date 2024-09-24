int BASE = 2;  //第一顆 LED 接的 I/O 腳
int NUM = 8;   //LED 的總數
int index = 0; //跑馬燈的計數指標，由0開始　
int D = 1000;  //延遲的時間
int VR_Pin =A0;
int VR_Value = 0;
int BUZZER = A9;
int RY5V = A4;

// the setup routine runs once when you press reset:
void setup() {      
   
   for (int i = BASE; i < BASE + NUM; i ++) {
     pinMode(i, OUTPUT);   //設定數字I/O腳為輸出
   }
   pinMode(BUZZER,OUTPUT);
   pinMode(VR_Pin,INPUT);   
   pinMode(A15, OUTPUT);
   digitalWrite(A15, LOW);
   pinMode(RY5V,OUTPUT);
   digitalWrite(RY5V,LOW);
}

// the loop routine runs over and over again forever:
void loop() {
   VR_Value = analogRead(VR_Pin);
   for (int i = BASE; i < BASE + NUM; i ++) { //設定數字I/O腳輸出為"低"，即沒有輸出
     digitalWrite(i, LOW);
   }
   delay(VR_Value);
   for (int i = BASE; i < BASE + NUM; i ++) {
     digitalWrite(i, HIGH);    //設定數字I/O腳輸出為"低"，即沒有輸出 
   }
   delay(VR_Value);
    if(VR_Value>500){
      digitalWrite(BUZZER, HIGH);
      digitalWrite(RY5V,HIGH);
     }
    else{
      digitalWrite(BUZZER, LOW);
      digitalWrite(RY5V,LOW);
    }
}

