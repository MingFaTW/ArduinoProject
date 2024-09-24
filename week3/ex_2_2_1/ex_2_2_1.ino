int RY5V = A4;

void setup() {
  // put your setup code here, to run once:
  pinMode(RY5V,OUTPUT);
  digitalWrite(RY5V,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(RY5V,HIGH);
  delay(1000);
  digitalWrite(RY5V,LOW);
  delay(1000);
}
