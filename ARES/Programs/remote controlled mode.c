#pragma config(Sensor, in1,    turPot,              sensorPotentiometer)
#pragma config(Sensor, dgtl7,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port3,           pServo,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           fServo,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           tMotor,        tmotorNormal, openLoop)
#pragma config(Motor,  port6,           blMotor,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port7,           brMotor,       tmotorNormal, openLoop)
#pragma config(Motor,  port8,           flMotor,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port9,           frMotor,       tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*************************************************************************************************
                                      RC Mode Overview

Four Drive Motors:
    Back Left Motor - blMotor - port 6 - reversed
    Back Right Motor - brMotor - port 7 - forward
    Front Left Motor - flMotor - port 8 - reversed
    Front Right Motor - frMotor - port 9 - reversed

One Turret Motor:
    Turret Motor - tMotor
        Clockwise for 36 or greater. need 38 to reach full range
        Counterclockwise for -24 or less

Two Functional Servos:
    Pan Servo - pServo - port 3 - negative = down and positive = up
        Top threshold =
        Bottom threshold =
    Fire Servo - fServo - port 4 - negative = fire and positive = stop firing

1 Digital Sensor:
    Sonar Sensor - sonarSensor - dgtl7 set for inches
    Description - prevents the user from running into an object. Forward movement will not be allowed.
                  Only reverse movement or turning left or right will be allowed.

1 Analog Sensor:
    Turret Potentiometer - turPot - in1
        Clockwise Minimum Range = 400
        Counterclockwise Maximum Range = 4000
        Description - limits the range of the turret so it doesn't go outside the bounds
                      allowed by certain wires

Controller Functions:

    Analog Joystick - Drive Control (option 1)
        x-axis = 1
        y-axis = 2
        Description - axis 1 controls turning left and right. Axis 2 controls movement forwarda and backwards.

    Analog Joystick - gun panning and turret rotation control (option 1)
        x-axis = 4
        y-axis = 3
        Description - axis 4 control turret rotation and axis 3 controls pan movement up and down

    Button Pad 8 - Drive Control (option 2)
        U Button - move forward
        D Button - move backwards
        L Button - turn left
        R Button - turn right
        Description - the individual button uses are listed above. this is the second option for drive control.

    Button Pad 7 - gun panning and turret rotation control (option 2)
        U Button - pan up
        D Button - pan down
        L Button - turn left
        R Button - turn right

    Button 6U - fire (option 1) - hold to fire and release to stop firing
    Button 5U - fire (option 2) - hold to fire and release to stop firing
        Description - it may be more convenient for some people to fire with the right hand and others
                      to fire with the left hand

    Button 5D - end program - must be pressed at the same time as button 6D
    Button 6D - end program - must be pressed at the same time as button 5D

Button/Axis to Motors/Sensors Mapping:

    Axis 1 - turn left or turn right (turn option 1)
    Axis 2 - move forward or move backwards (movement option 1)

    Axis 3 - Pan Servo - pServo (pan option 1)
    Axis 4 - Turret Motor - tMotor (turret option 2)

    Button 5U - Fire Servo - fServo - hold to fire (fire option 1)
    Button 6U - Fire Servo - fServo - hold to fire (fire option 2)

    Button 5D - end program - must be pressed at same time as button 6D
    Button 6D - end program - must be pressed at same time as button 5D

    Button 7U - Pan Servo - pServo - pan up (pan option 2)
    Button 7D - Pan Servo - pServo - pan down (pan option 2)
    Button 7L - Turret Motor - tMotor - rotate counterclockwise (turret option 2)
    Button 7R - Turret Motor - tMotor - rotate clockwise (turret option 2)

    Button 8U - move forward - speed = 128 all motors (movement option 2)
    Button 8D - move backward - speed = -128 all motors (movement option 2)
    Button 8L - turn left - speed = 128 right motors and -128 left motors (turn option 2)
    Button 8R - turn right - speed = -128 right motors and 128 left motors (turn option 2)

***************************************************************************************************/


/********************************Global Variables and Constants*************************************/

// motor and servo constants
const int DRIVE_SPEED = 128;

const int TURRET_CW_SPEED = 45;
const int TURRET_CCW_SPEED = -30;

const int PAN_START_LOC = 0;
const int PAN_MOVE = 10;
const int MAX_PAN_VAL = 60;
const int MIN_PAN_VAL = -20;
const int PAN_SERVO_MOVE_TIME = 200;

const int FIRE = -40;
const int STOP_FIRE = 50;

// sensor constants
const int MINIMUM_DISTANCE = 5;

const int MAX_CCW_POT_VAL = 3700;
const int MIN_CW_POT_VAL = 400;
const int TURRET_CENTER = 1865;

// remote control constants
const int JOYSTICK_THRESHOLD = 90;


/***********************************Function Prototypes*********************************************/
void initialize_and_end();
void dSpeed( int blSpeed, int brSpeed, int flSpeed, int frSpeed );
void tSpeed( int turSpeed );

/*****************************************Pan******************************************************/
//pan is separate from main because the pan servo requires a small amount of time to change positions
//if this time is not allowed, the gun will abruptly jump to from its max location to its min location
//and vice versa
task pan()
{
    int panLoc = PAN_START_LOC;

    while( true )
    {
        //Pan Control - both options implemented here
        if( ( vexRT[ch3] < -JOYSTICK_THRESHOLD || vexRT[Btn7U] == 1 ) && panLoc < MAX_PAN_VAL )
        {
            panLoc += PAN_MOVE;
            motor[pServo] = panLoc;

        }//end if
        else if( ( vexRT[ch3] > JOYSTICK_THRESHOLD || vexRT[Btn7D] == 1 ) && panLoc > MIN_PAN_VAL )
        {
            panLoc -= PAN_MOVE;
            motor[pServo] = panLoc;

        }//end else if

        wait1Msec(PAN_SERVO_MOVE_TIME);

    }//end while

}//end pan

/*****************************************Main******************************************************/
task main()
{
  initialize_and_end();
  bool endProgram = false;
  startTask(pan);

  while( endProgram != true )
  {

    //Drive Control both options implemented here
    int senVal = sensorValue[sonarSensor];
    if( ( vexRT[ch2] > JOYSTICK_THRESHOLD || vexRT[Btn8U] == 1 ) && ( senVal > MINIMUM_DISTANCE || senVal < 0 ) )
      dSpeed( DRIVE_SPEED, DRIVE_SPEED, DRIVE_SPEED, DRIVE_SPEED );
    else if( vexRT[ch2] < -JOYSTICK_THRESHOLD || vexRT[Btn8D] == 1 )
      dSpeed( -DRIVE_SPEED, -DRIVE_SPEED, -DRIVE_SPEED, -DRIVE_SPEED );
    else if( vexRT[ch1] < -JOYSTICK_THRESHOLD || vexRT[Btn8L] == 1 )
      dSpeed( -DRIVE_SPEED, DRIVE_SPEED, -DRIVE_SPEED, DRIVE_SPEED );
    else if( vexRT[ch1] > JOYSTICK_THRESHOLD || vexRT[Btn8R] == 1 )
      dSpeed( DRIVE_SPEED, -DRIVE_SPEED, DRIVE_SPEED, -DRIVE_SPEED );
    else dSpeed( 0, 0, 0, 0 );

    //Turret Control - both options implemented here
    if( ( vexRT[ch4] < -JOYSTICK_THRESHOLD || vexRT[Btn7L] == 1 ) && sensorValue[turPot] < MAX_CCW_POT_VAL )
      tSpeed( TURRET_CCW_SPEED );
    else if( ( vexRT[ch4] > JOYSTICK_THRESHOLD || vexRT[Btn7R] == 1 ) && sensorValue[turPot] > MIN_CW_POT_VAL )
      tSpeed( TURRET_CW_SPEED );
    else tSpeed( 0 );

    //Fire Control
    if( vexRT[Btn6U] == 1 || vexRT[Btn5U] == 1 )
      motor[fServo] = FIRE;
    else motor[fServo] = STOP_FIRE;

    //end program check
    if( vexRT[Btn6D] == 1 && vexRT[Btn5D] == 1 )
      endProgram = true;

  }//end while

  stopTask(pan);

  initialize_and_end();

}//end main

/***********************************************Methods*******************************************************/
void dSpeed( int blSpeed, int brSpeed, int flSpeed, int frSpeed )
{
  motor[blMotor] = blSpeed;
  motor[brMotor] = brSpeed;
  motor[flMotor] = flSpeed;
  motor[frMotor] = frSpeed;

}//end dSpeed

void tSpeed( int turSpeed )
{
  motor[tMotor] = turSpeed;

}//end tSpeed

void initialize_and_end()
{
  dSpeed( 0, 0, 0, 0 );
  motor[fServo] = STOP_FIRE;
  motor[pServo] = PAN_START_LOC;

  if( sensorValue[turPot] > TURRET_CENTER )
  {
    motor[tMotor] = TURRET_CW_SPEED;

    while( sensorValue[turPot] > TURRET_CENTER )
      {/*wait*/}//end while

  }//end if
  else
  {
    motor[tMotor] = TURRET_CCW_SPEED;

    while( sensorValue[turPot] < TURRET_CENTER )
      {/*wait*/}//end while

  }//end else

  motor[tMotor] = 0;

}//end end
