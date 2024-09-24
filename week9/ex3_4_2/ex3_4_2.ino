const int motorIn1 = 2;
const int motorIn2 = 3;
const int tt = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int i;
  digitalWrite(motorIn2,LOW);
  for(i=100;i<=255;i+=10){
    analogWrite(motorIn1,i);
    delay(tt);
  }
  for(i=255;i>=100;i-=10){
    analogWrite(motorIn1,i);
    delay(tt);
  }
}
