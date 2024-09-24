int BASE = 6;
int NUM = 4;
int BASE1 = 33;
int K1state;
int K2state;
int K3state;
int K4state;


void setup() {
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
}

void loop() {
  // put your main code here, to run repeatedly: 
  K1state = digitalRead(33);
  digitalWrite(9,K1state);
  Serial.println(K1state);
  
  K2state = digitalRead(34);
  digitalWrite(8,K2state);
  
  K3state = digitalRead(35);
  digitalWrite(7,K3state);
  
  K1state = digitalRead(36);
  digitalWrite(6,K4state);
}
