int VR_Pin = A0;
int VR_Value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  VR_Value = analogRead(VR_Pin);
  Serial.print("VR_Value = ");
  Serial.println(VR_Value);
  delay(10);
}
