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
  printf("%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);
  printf("%f %f\n",initialMotorPower-motorPowerDifference,initialMotorPower+motorPowerDifference);
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
  while(seconds()<elapsedTime)
  {
    motor(0,70);
    motor(1,70);
  }
  disable_servo(SERVO_LIFT);
  currentValue=analog(0);
  elapsedTime+=seconds()+30;
  while (seconds()<elapsedTime)
  {
    printf("(debug)%d   %f\n",currentValue,elapsedTime-seconds());
    currentValue=analog(0);
    PID_lineFollow();
  }
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
  //ballCollect();
  return 0;
}
