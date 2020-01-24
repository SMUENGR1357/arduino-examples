#include <KNWRobot.h>

#define SERVO_ID  1 //set ID for servo 
#define SERVO_PIN 1 //setup to be whatever pin you end up using

//Servo setup

//REMEMBER: Set the servo to 0 degrees first to get it exactly to where it should start very time you use the servo. Reset servo to 0 at end

KNWRobot*  robot;

void setup() {
  // put your setup code here, to run once:
  robot = new KNWRobot();
  robot->setupServo(SERVO_ID, SERVO_PIN); //setup servo given parameters ID and Pin
}

void loop() {
  // put your main code here, to run repeatedly:
  robot->pca180Servo(SERVO_ID, 0); //turn servo to 0 degrees
  delay(1000);
  robot->pca180Servo(SERVO_ID, 90); //turn servo to 90 degrees
  delay(1000);
  robot->pca180Servo(SERVO_ID, 180); //turn servo to 180 degrees
  delay(1000);
  robot->pca180Servo(SERVO_ID, 0); //turn servo to 0 degrees
  delay(1000);

  while(1) delay(5000); //while true (always) don't run
}
