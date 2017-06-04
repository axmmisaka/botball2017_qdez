//PID Algorithm is an algorithm that could make the robot follow the line without huge swing.
//This program can let the wallaby follow the black line and climb the ramp
//Finished by Charlie5381 and axmmisaka
//Variables names and some details are changed by axmmisaka

#include <kipr/botball.h>
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
const int MotorPower=50;//TODO: try changing these globals vars into local
int MotorPowerDifference=0;
int MotorPowerAlternateRatio=0;
int offset=(2100+3900)/2;//offset = Tophat detected white + black /2
float AdjustmentRatio=0.05/*(100-0)/(3900-2100)*/;//AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int CurrentValue;
void LineFollow()//Will follow right edge of the BLACK duct tape
{
	MotorPowerAlternateRatio = CurrentValue - offset;
  	MotorPowerDifference = AdjustmentRatio * MotorPowerAlternateRatio;
  	printf("%f\n",AdjustmentRatio);
  	motor(MOTOR_LEFT, MotorPower - MotorPowerDifference);
  	motor(MOTOR_RIGHT, MotorPower + MotorPowerDifference);
}
int main()
{
    float elapsedTime;
  	elapsedTime=seconds()+3;
  	while(seconds()<elapsedTime)
    {
  		motor(MOTOR_LEFT,70);
  		motor(MOTOR_RIGHT,70);
    }//Climb onto the ramp
  	CurrentValue=analog(0);
  	elapsedTime=seconds()+10;
  	while (seconds()<elapsedTime)
    {
      	printf("%d\n",CurrentValue);
    	CurrentValue=analog(0);
      	LineFollow();
    }
  	elapsedTime=seconds()+2;
  	while (seconds()<elapsedTime)
    {
    	motor(0,MotorPower);
      	motor(1,MotorPower);
    }//get of the ramp, 2sec
    return 0;
}
