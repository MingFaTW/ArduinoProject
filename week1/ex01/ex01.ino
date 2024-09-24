
int led = 4;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
}

void loop() {   
  // put your main code here, to run repeatedly: 
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
