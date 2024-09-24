int VR_Pin =A5;
int VR_Value = 0;
int ledPin = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  VR_Value = analogRead(VR_Pin);
  digitalWrite(ledPin,HIGH);
  delay(VR_Value);
  digitalWrite(ledPin,LOW);
  delay(VR_Value);
}
