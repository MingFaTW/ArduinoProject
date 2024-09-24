const int motorIn1 = 2;
const int motorIn2 = 3;
const int DELAY = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  forward();
  delay(DELAY);
  motorstop();
  delay(500);
  backward();
  delay(DELAY);
  motorstop();
  delay(500);
}

void motorstop(){
  digitalWrite(motorIn1,LOW);
  digitalWrite(motorIn2,LOW);
}

void forward(){
  digitalWrite(motorIn1,HIGH);
  digitalWrite(motorIn2,LOW);
}

void backward(){
  digitalWrite(motorIn1,LOW);
  digitalWrite(motorIn2,HIGH);
}

