#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
#include<Stepper.h>
Stepper stepper(200,A,A_BAR,B,B_BAR);

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(20);
}

void loop() {
  // put your main code here, to run repeatedly: 
  stepper.step(200);
  stepper.step(-200);
}
