#include <KNWRobot.h>

KNWRobot* robot;

/* In this example, we'll make the IDs for sensors the same as their pins */

#define IR_PIN 1
#define IR_ID IR_PIN 

#define PING_PIN 2
#define PING_ID PING_PIN

#define INCLINE_PIN 3


void setup() {
  robot = new KNWRobot();  
  robot->setupIR( IR_ID, IR_PIN );
  robot->setupPing( PING_ID, PING_PIN );
  robot->setupIncline( INCLINE_PIN );
}

void loop() {
  /* Get IR reading... note: you may wish to cast this to a char */
  int ir_result = robot->scanIR( IR_ID );
  /* Get ping from sensor */
  long ping_result = robot->getPing( PING_ID );
  /* Get incline from sensor */
  int incline = robot->getIncline( );
  
  while(1) delay(5000);
}
