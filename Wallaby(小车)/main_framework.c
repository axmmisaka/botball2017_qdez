//Finished by Charlie5381 and axmmisaka
#define SERVO_LIFT 0
#define SERVO_CATCH 1

#include <kipr/botball.h>
const int initialMotorPower=75;
float motorPowerDifference=0;
int motorPowerAlternateRatio=0;
int offset=(3800+1500)/2;//offset = Tophat detected white + black /2
float elapsedTime;
float AdjustmentRatio=100.0/2300.0;/*(100-0)/(3900-2100)*///AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int currentValue;
void check()
{

	int i=200;
  while (i<=1900)
    {
    	set_servo_position(0,i);
      	i+=1;
      	msleep(1);
  	}
  set_servo_position(1,300);
  set_servo_position(1,1200);
   set_servo_position(1,300);
  msleep(500);
    set_servo_position(1,1200);
  msleep(500);
    set_servo_position(1,300);
  msleep(500);
    while (i>=200)
    {
    	set_servo_position(0,i);
      	i-=1;
      	msleep(1);
  	}
}
void PID_lineFollow()
{
  motorPowerAlternateRatio=currentValue-offset;
  motorPowerDifference=AdjustmentRatio*motorPowerAlternateRatio;
  printf("(DEBUG)%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);
  printf("(DEBUG)%f %f\n",initialMotorPower-motorPowerDifference,initialMotorPower+motorPowerDifference);
  motor(0,initialMotorPower+motorPowerDifference);
    motor(2,initialMotorPower+motorPowerDifference);
  motor(1,initialMotorPower-motorPowerDifference);
    motor(4,initialMotorPower-motorPowerDifference);
}
void initialization()
{
  set_servo_position(0,200);
  set_servo_position(1,1200);
}
void pid()
{
	motorPowerAlternateRatio=currentValue-2250;
 	motorPowerDifference=(100.0/(3800.0-700.0))*motorPowerAlternateRatio;
 	printf("(DEBUG)%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);
 	printf("(DEBUG)%f %f\n",70-motorPowerDifference,70+motorPowerDifference);
  motor(0,initialMotorPower+motorPowerDifference);
    motor(2,initialMotorPower+motorPowerDifference);
  motor(1,initialMotorPower-motorPowerDifference);
    motor(4,initialMotorPower-motorPowerDifference);
}
void ascent()
{
  set_servo_position(SERVO_LIFT,300);
  msleep(1000);
  motor(0,70);
  motor(1,70);
  msleep(200);
  motor(0,0);
  motor(1,0);
  int i=1200;
  while (i>=200)
    {
    	set_servo_position(1,i);
      	i-=1;
      	msleep(1);
  	}
  msleep(1000);
  motor(0,-70);
  motor(1,-70);
  msleep(200);
  motor(0,0);
  motor(1,0);
  set_servo_position(0,1000);
  msleep(1000);
  motor(0,70);
  motor(1,70);
  msleep(200);
  motor(0,0);
  motor(1,0);
  msleep(1000);
  
  elapsedTime=seconds()+1.5;
  printf("(DEBUG)%f  %f  %f",elapsedTime,seconds(),elapsedTime-seconds());
  while(seconds()<elapsedTime)
  {
    motor(0,70);
    motor(1,70);
  }
  motor(0,1);
  motor(1,1);
  set_servo_position(0,200);
  msleep(1000);
  currentValue=analog(0);
  elapsedTime=seconds()+4.4;
  while (seconds()<elapsedTime)
  {
    printf("(debug)%f\n",elapsedTime-seconds());
    currentValue=analog(0);
    PID_lineFollow();
  }
  printf("shang\n");
  //enable_servo(0);
  motor(0,1);
  motor(1,1);
  set_servo_position(0,500);
  msleep(1000);
  elapsedTime = seconds()+0.7;
  while (seconds()<elapsedTime )
  {
  	motor(0,80);
    motor(1,80);
  }
   motor(0,1);
  motor(1,1);
  msleep(2000);
  motor(0,70);
  motor(1,70);
  msleep(1000);
  motor(0,0);
  motor(1,0);
  msleep(1000);
    set_servo_position(0,200);
  msleep(1000);
  set_servo_position(1,1200);
  msleep(1000);
  motor(0,-10);
  motor(1,-10);
  i=200;
  while (i<=450)
  {
    set_servo_position(0,i);
    i+=1;
  msleep(10);
  }
  msleep(1500);
//  motor(0,-70);
//  motor(1,-70);
//  msleep(1000);
  motor(0,0);
  motor(1,0);
  msleep(1000);
      set_servo_position(0,200);
  msleep(1000);
  elapsedTime = seconds()+1;
  while (seconds()<elapsedTime)
  {
  	motor(0,80);
    motor(1,80);
  }
//    motor(0,1);
 // motor(1,1);
  //msleep(2000);
  elapsedTime = seconds()+8;
  while (seconds()<elapsedTime && (analog(2) || elapsedTime-seconds()>4.5))
  {  
    currentValue=analog(0);
    pid();
    printf("%f\n",elapsedTime-seconds());
  }
  motor(0,0);
  motor(1,0);
  msleep(2000);
}
void ballCollect()
{
  //set_servo_position(SERVO_LIFT,500);
  elapsedTime=seconds()+10;
  int i=1200;
  while (seconds()<elapsedTime)
  {
    
    motor(0,-10);
    motor(1,-10);
    msleep(1500);
    while (i>=200)
    {
    	set_servo_position(1,i);
      	i-=1;
      	msleep(1);
  	}
  }
  i=200;
  while (i<=2000)
  {
  	set_servo_position(0,i);
    i+=1;
    msleep(1);
  }
  elapsedTime=seconds()+2.5;
  while (seconds()<elapsedTime)
  {
    motor(0,100);
    motor(1,70);
  //	currentValue=analog(0);
  //  pid();
  }
  motor(0,-70);
  motor(1,-100);
  msleep(1500);
  motor(0,100);
  motor(1,100);
  msleep(1500);
  motor(0,0);
  motor(1,0);
  set_servo_position(0,1700);
  msleep(1000);
  set_servo_position(1,1200);
  msleep(2000);
    set_servo_position(0,1900);
  motor(0,-30);
  motor(1,-30);
  msleep(2000);
  motor(0,30);
  motor(1,30);
  msleep(2000);
  motor(0,0);
  motor(1,0);
  msleep(1000);
  set_servo_position(0,1700);
   set_servo_position(1,300);
  msleep(500);
    set_servo_position(1,1200);
  msleep(500);
    set_servo_position(1,300);
  msleep(500);
    set_servo_position(1,1200);
  msleep(500);
    set_servo_position(1,300);
  msleep(500);
    set_servo_position(1,1200);
  msleep(500);
    set_servo_position(1,300);
  msleep(500);
    set_servo_position(1,1200);
  msleep(500);
}
int main()
{
      enable_servo(SERVO_LIFT);
  enable_servo(SERVO_CATCH);
 // check();
  initialization();
  printf("READY...\n");
  while (1)
  {
    if (analog(1)<=200)
    { 
      printf("20s left to begin\n");
      msleep(20000);
   	 ascent();
		// moveOntoUpperArea();
 		 ballCollect();
    break;
  	}
  }
  return 0;
}
