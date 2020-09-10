task main()
{
   //rotate counterclockwise
  motor[port5] = -30;
  wait1Msec(500);

  //rotate clockwise
  motor[port5] = 50;
  wait1Msec(1000);

  //rotate counterclockwise
  motor[port5] = -30;
  wait1Msec(500);

}//end main
