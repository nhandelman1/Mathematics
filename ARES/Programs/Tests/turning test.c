#pragma config(Motor,  port6,           blMotor,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port7,           brMotor,       tmotorNormal, openLoop)
#pragma config(Motor,  port8,           flMotor,       tmotorNormal, openLoop)
#pragma config(Motor,  port9,           frMotor,       tmotorNormal, openLoop, reversed)

task main()
{
  wait1Msec(2000);

  motor[blMotor] = 127;
  motor[brMotor] = -127;
  motor[flMotor] = 127;
  motor[frMotor] = -127;
  wait1Msec(2000);

}//end main
