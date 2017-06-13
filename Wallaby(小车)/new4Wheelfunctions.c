#include <kipr/botball.h>
const int initialMotorPower=75;
float motorPowerDifference=0;
int motorPowerAlternateRatio=0;
int offset=(3900+2700)/2;//offset = Tophat detected white + black /2
float elapsedTime;
float AdjustmentRatio=100.0/1200.0;/*(100-0)/(3900-2100)*/
//AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int currentValue;
void PID_lineFollow(){
motorPowerAlternateRatio=currentValue-offset;  
motorPowerDifference=AdjustmentRatio*motorPowerAlternateRatio;  
printf("(DEBUG)%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);  
printf("(DEBUG)%f %f\n",initialMotorPower-motorPowerDifference,initialMotorPower+motorPowerDifference);    
motor(2,initialMotorPower-motorPowerDifference);    
motor(3,initialMotorPower+motorPowerDifference);}
