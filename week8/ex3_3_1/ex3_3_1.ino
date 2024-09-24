int Pin = A6;
int Value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Value = analogRead(Pin);
  Serial.print("Value = ");
  Serial.println(Value);
  delay(1000);
}
