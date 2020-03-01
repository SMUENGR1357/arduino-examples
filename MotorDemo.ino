#include <KNWRobot.h>

#define LEFT_MOTOR_PIN    4 // Left motor will be on pin 4
#define LEFT_MOTOR_ID     1 // Left motor will have ID of 1
#define RIGHT_MOTOR_PIN   5 // Right motor will be on pin 5
#define RIGHT_MOTOR_ID    2 // Right motor will have ID of 2

#define LEFT_MOTOR_SPEED  500
#define RIGHT_MOTOR_SPEED 500

KNWRobot* robot;

void setup() {
  robot = new KNWRobot();
  robot->setupMotor(LEFT_MOTOR_ID, LEFT_MOTOR_PIN);
  robot->setupMotor(RIGHT_MOTOR_ID, RIGHT_MOTOR_PIN); 
}

void loop() {
  /* Example of starting motors (they will run until you tell them to stop!) */
  robot->pcaDC2Motors(
    /* Motor 1 ID and Speed */ LEFT_MOTOR_ID, LEFT_MOTOR_SPEED, 
    /* Motor 2 ID and Speed */ RIGHT_MOTOR_ID, RIGHT_MOTOR_SPEED );
  
  /* Stop left motor, then right motor */
  robot->pcaStop( LEFT_MOTOR_ID );
  robot->pcaStop( RIGHT_MOTOR_ID );

  /* Wait for five seconds (delay function takes milliseconds) */
  delay(5000);

  /* Run left and right motors for five seconds (they will stop automatically after that time) */
  robot->pcaDC2MotorsTime(
    /* Motor 1 ID and Speed */ LEFT_MOTOR_ID, LEFT_MOTOR_SPEED, 
    /* Motor 2 ID and Speed */ RIGHT_MOTOR_ID, RIGHT_MOTOR_SPEED,
    /* Time (in milliseconds) to run motor */ 5000 );

  /* Delay infinitely... */
  while(1) delay(5000);
}
