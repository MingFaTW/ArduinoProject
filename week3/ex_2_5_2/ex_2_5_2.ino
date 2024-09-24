int redPin = 44;
int grnPin = 45;
int bluPin = 46;
int speed = 10;
int r_value = 0;
int g_value = 0;
int b_value = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(grnPin,OUTPUT);
  pinMode(bluPin,OUTPUT);
  analogWrite(redPin, 255);
  analogWrite(grnPin, 255);
  analogWrite(bluPin, 255);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int r_value = random(0,255);
  int g_value = random(0,255);
  int b_value = random(0,255);
  analogWrite(redPin, r_value);
  analogWrite(redPin, g_value);
  analogWrite(redPin, b_value);
  delay(speed);
}
