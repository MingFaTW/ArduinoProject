int Pin = A6;
int Value = 0;
const int motorIn1 = 2;
const int motorIn2 = 3;
const int tt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Value = analogRead(Pin);
  Serial.print("Value = ");
  Serial.println(Value);
  int i=100;
  digitalWrite(motorIn2,LOW);
  if(Value>700){
    for(i;i<=255;i+=10){
      analogWrite(motorIn1,i);
      //delay(tt);
    }
  }
  if(Value<600){
    for(i;i>=0;i-=10){
      analogWrite(motorIn1,i);
      //delay(tt);
    }
  }
}
