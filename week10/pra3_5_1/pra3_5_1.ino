#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
#include<Stepper.h>
Stepper stepper(200,A,A_BAR,B,B_BAR);
//ex2-10-1
int VR_Pin = A0;
int VR_Value = 0;

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(20);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  VR_Value = analogRead(VR_Pin);
  Serial.print("VR_Value = ");
  Serial.println(VR_Value);
  stepper.setSpeed(VR_Value);
  stepper.step(50);
  delay(10);
}
