int redPin = 44;
int grnPin = 45;
int bluPin = 46;
int speed = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(grnPin,OUTPUT);
  pinMode(bluPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  analogWrite(redPin, 255);
  analogWrite(grnPin, 255);
  analogWrite(bluPin, 255);
  for(int i=0;i<255;i++){
    analogWrite(redPin, i);
    delay(speed);
  }
  delay(100);
  for(int i=0;i<255;i++){
    analogWrite(grnPin, i);
    delay(speed);
  }
  delay(100);
  for(int i=0;i<255;i++){
    analogWrite(bluPin, i);
    delay(speed);
  }
  delay(100);
}
