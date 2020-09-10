task main()
{
  wait1Msec(3000);

  //reverse ports 6,8 and 9
  bMotorReflected[port6] = true;
  bMotorReflected[port8] = true;
  bMotorReflected[port9] = true;

  motor[port9] = 127;
  wait1Msec(3000);
  /*//go forward for 3 seconds
  motor[port6] = 127;
  motor[port7] = 127;
  motor[port8] = 127;
  motor[port9] = 127;
  wait1Msec(3000);

  //go reverse for 3 seconds
  motor[port6] = -127;
  motor[port7] = -127;
  motor[port8] = -127;
  motor[port9] = -127;
  wait1Msec(3000);

  //go forward left for 3 seconds (full turn)
  motor[port6] = 20;
  motor[port7] = 127;
  motor[port8] = 20;
  motor[port9] = 127;
  wait1Msec(3000);

  //go reverse left for 3 seconds (full turn)
  motor[port6] = -20;
  motor[port7] = -127;
  motor[port8] = -20;
  motor[port9] = -127;
  wait1Msec(3000);

  //go forward right for 3 seconds (full turn)
  motor[port6] = 127;
  motor[port7] = 20;
  motor[port8] = 127;
  motor[port9] = 20;
  wait1Msec(3000);

  //go reverse right for 3 seconds (full turn)
  motor[port6] = -127;
  motor[port7] = -20;
  motor[port8] = -127;
  motor[port9] = -20;
  wait1Msec(3000);

  //go left for 3 seconds (in place turn)
  motor[port6] = -127;
  motor[port7] = 127;
  motor[port8] = -127;
  motor[port9] = 127;
  wait1Msec(3000);

  //go right for 3 seconds (in place turn)
  motor[port6] = 127;
  motor[port7] = -127;
  motor[port8] = 127;
  motor[port9] = -127;
  wait1Msec(3000); */

}//end main
