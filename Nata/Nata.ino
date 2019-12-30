#include <VarSpeedServo.h>

VarSpeedServo servoMotor;

void setup() {
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  servoMotor.attach(7);
}

void loop() {

  //MOtror horizibtal
  randomSeed(analogRead(A1));
  digitalWrite(12, HIGH);
  delay(random(100,4000));
  randomSeed(analogRead(A2));
  digitalWrite(12, LOW);
  delay(random(100,4000));
  randomSeed(analogRead(A3));
  digitalWrite(10, HIGH);
  delay(random(100,4000));
  randomSeed(analogRead(A4));
  digitalWrite(10, LOW);
  delay(random(100,4000));

  // MOtror vertical
  randomSeed(analogRead(A1));
  digitalWrite(5, HIGH);
  delay(random(100,4000));
  randomSeed(analogRead(A2));
  digitalWrite(5, LOW);
  delay(random(100,4000));
  randomSeed(analogRead(A3));
  digitalWrite(3, HIGH);
  delay(random(100,4000));
  randomSeed(analogRead(A4));
  digitalWrite(3, LOW);
  delay(random(100,4000));

  //Servo 
  randomSeed(analogRead(A1));
  servoMotor.write(random(60,180),random(1,70),true);
  //servoMotor.write(60);
  delay(random(100,1000));
}
