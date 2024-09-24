int BUZZER = A9;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(BUZZER,HIGH);
  delay(1000);
  digitalWrite(BUZZER,LOW);
  delay(1000);
}
