int BUZZER = A9;
int VR_pin = A0;
int VR_value = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER,OUTPUT);
  pinMode(VR_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  VR_value = analogRead(VR_pin);
  digitalWrite(BUZZER,HIGH);
  delay(VR_value);
  digitalWrite(BUZZER,LOW);
  delay(VR_value);
}
