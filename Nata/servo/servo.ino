#include <Servo.h>

Servo servoMotor;

void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  randomSeed(analogRead(A1));
  servoMotor.write(random(95,175));
  //servoMotor.write(180);
  delay(random(100,1000));
}
