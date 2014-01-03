#include <Servo.h>
Servo servo;
int const potPin = A0;
int potVal;
int angle;

void setup(){
  servo.attach(9);
}

void loop(){
  potVal = analogRead(potPin);
  angle = map(potVal, 0, 1023, 0, 179);
  servo.write(angle);
  delay(15);
}
