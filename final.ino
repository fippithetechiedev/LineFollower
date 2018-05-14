// BY PHILIP GEORGE (2016)
// TECHNOSHOTS

#include <AFMotor.h>

AF_DCMotor leftmotor(2);
AF_DCMotor rightmotor(3);

void setup() {
  pinMode(5, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  leftmotor.setSpeed(100);
 rightmotor.setSpeed(100);

  leftmotor.run(RELEASE);
  rightmotor.run(RELEASE);
}

void loop() {
  uint8_t l, r;
  l = digitalRead(5);
  r = digitalRead(10);
  Serial.print(l);

  if (l == 1 && r == 0)
  { leftmotor.run(RELEASE);
  rightmotor.run(FORWARD);
  }
  else if (l == 0 && r == 1)
  { rightmotor.run(RELEASE);
    leftmotor.run(FORWARD);
  }
  else if(l==0 && r==0)
  {
    rightmotor.run(RELEASE);
    leftmotor.run(FORWARD);
  }


}
