//PID Algorithm is an algorithm that could make the robot follow the line without huge swing.
//This program can let the wallaby follow the black line and climb the ramp
//Finished by Charlie5381

#include <kipr/botball.h>
const int MotorPower=50;
int MotorPowerDifference=0;
int MotorPowerAlternateRatio=0;
int offset=(245+3700)/2;//offset = Tophat detected white + black /2
float time;
float AdjustmentRatio=0.06;//AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int CurrentValue;
void LineFollow()
{
	MotorPowerAlternateRatio=CurrentValue-offset;
  	MotorPowerDifference=AdjustmentRatio*MotorPowerAlternateRatio;
  	printf("%f\n",AdjustmentRatio);
  	motor(0,MotorPower-MotorPowerDifference);
  	motor(1,MotorPower+MotorPowerDifference);
}
int main()
{
  	time=seconds()+3;
  	while(seconds()<time)
    {
  		motor(0,70);
  		motor(1,70);
    }//Climb onto the ramp
  	CurrentValue=analog(0);
  	time+=10;
  	while (seconds()<time)
    {
      	printf("%d\n",CurrentValue);
    	CurrentValue=analog(0);
      	LineFollow();
    }
  	time+=2;
  	while (seconds()<time)
    {
    	motor(0,MotorPower);
      	motor(1,MotorPower);
    }
    return 0;
}
