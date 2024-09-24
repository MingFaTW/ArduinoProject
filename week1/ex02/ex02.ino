int BASE = 2;
int NUM = 8;
int index = 0;
int D = 1000;

void setup() {
  // put your setup code here, to run once:
  for(int i=BASE;i<BASE+NUM;i++){
    pinMode(i,OUTPUT);
  }
    pinMode(A15,OUTPUT);
    digitalWrite(A15,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i=BASE;i<BASE+NUM;i++){
    digitalWrite(i,LOW);
  }  
  delay(D);
  for(int i=BASE;i<BASE+NUM;i++){
    digitalWrite(i,HIGH);
  }
  delay(D);
}
