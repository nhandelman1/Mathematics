task main()
{
  while( true )
  {
  //fire gun = switch on
  motor[port4] = -40;
  wait1Msec(500);
  //stop firing = switch off
  motor[port4] = 50;
  wait1Msec(300);
  }
}
