/*************************************************************/
/*Some before-running initializations*/
/*Connections:Left wheel on Motor 0, with red side towards the screen.*/
/*Right wheel on Motor 1, with black side towards the screen.*/
/*The nearer servo, mounted onto the upright post is connected on servo 0*/
/*The another servo, servo 1 which controls the open and closeof mechanican hand, is connected on servo 2*/
/*Tophat sensor is mounted on analog 0, light sensor is mounted on analog 1.*/
/*The back wheel has a distance of 17.5 centimeter from the outer border of the starting area horizontally, 8.5 cm vertically*/
/*************************************************************/




//Finished by Charlie5381 and axmmisaka
#define SERVO_LIFT 0
#define SERVO_CATCH 1

#include <kipr/botball.h>
const int initialMotorPower=75;
float motorPowerDifference=0;
int motorPowerAlternateRatio=0;
int offset=(3850+1750)/2;//offset = Tophat detected white + black /2
float elapsedTime;
float AdjustmentRatio=80.0/2100.0;/*(100-0)/(3900-2100)*///AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int currentValue;
void PID_lineFollow()
{
  motorPowerAlternateRatio=currentValue-offset;
  motorPowerDifference=AdjustmentRatio*motorPowerAlternateRatio;
  printf("(DEBUG)%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);
  printf("(DEBUG)%f %f\n",initialMotorPower-motorPowerDifference,initialMotorPower+motorPowerDifference);
  motor(0,initialMotorPower+motorPowerDifference);
  motor(1,initialMotorPower-motorPowerDifference);
}
void initialization()
{
  enable_servo(SERVO_LIFT);
  enable_servo(SERVO_CATCH);
  set_servo_position(SERVO_LIFT,650);
  set_servo_position(SERVO_CATCH,1200);
}
void ascent()
{
  elapsedTime=seconds()+2;
  printf("(DEBUG)%f  %f  %f",elapsedTime,seconds(),elapsedTime-seconds());
  while(seconds()<elapsedTime)
  {
    motor(0,70);
    motor(1,70);
  }
  disable_servo(SERVO_LIFT);
  currentValue=analog(0);
  elapsedTime=seconds()+5.1;
  while (seconds()<elapsedTime)
  {
    printf("(debug)%f\n",elapsedTime-seconds());
    currentValue=analog(0);
    PID_lineFollow();
  }
}
void moveOntoUpperArea()
{
  int servo_pos = 0;
  enable_servo(SERVO_LIFT);
  elapsedTime = seconds()+2;
  while(seconds()<elapsedTime)
  {
    set_servo_position(SERVO_LIFT,servo_pos = servo_pos < 400 ? servo_pos + 5:400);
    motor(0,80);
    motor(1,80);
  }
  disable_servo(SERVO_LIFT);
  PID_lineFollow();
}
void ballCollect()
{
  set_servo_position(SERVO_LIFT,500);
  elapsedTime+=1;
  while (seconds()<elapsedTime)
  {
    motor(0,initialMotorPower);
    motor(1,initialMotorPower);
  }
  elapsedTime+=1;
  while (seconds()<elapsedTime)
  {
    currentValue=analog(0);
    PID_lineFollow();
  }
  motor(0,0);
  elapsedTime+=3;
  int i=1200;
  while (seconds()<elapsedTime)
  {
    motor(0,-10);
    motor(1,-10);
    while (i>530)
    {
      i-=10;
      set_servo_position(0,i);
      msleep(10);
    }
  }
  motor(0,0);
  motor(1,0);
  i=500;
  while (i<2000)
  {
    i+=10;
    set_servo_position(SERVO_LIFT,i);
    msleep(10);
  }
  motor(0,initialMotorPower);
  motor(1,initialMotorPower);
  msleep(100);
  set_servo_position(SERVO_LIFT,1800);
  set_servo_position(SERVO_CATCH,1000);

}
int main()
{
  initialization();
  printf("initialization success...\nBoiling Vodka!\n");
  ascent();
  moveOntoUpperArea();
  //ballCollect();
  return 0;
}
