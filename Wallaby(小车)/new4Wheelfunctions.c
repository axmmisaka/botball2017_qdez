#include <kipr/botball.h>
#define LEFT -1
#define RIGHT 1
const int initialMotorPower=75;
float motorPowerDifference=0;
int motorPowerAlternateRatio=0;
int offset=(3900+2700)/2;//offset = Tophat detected white + black /2
float elapsedTime;
float AdjustmentRatio=100.0/1200.0;/*(100-0)/(3900-2100)*/
//AdjustmentRatio = (MotorMax-MotorMin)/(Tophat detected black - white)
int currentValue;
//remember to update currentValue!
void PID_lineFollow(){
  motorPowerAlternateRatio=currentValue-offset;  
  motorPowerDifference=AdjustmentRatio*motorPowerAlternateRatio;  
  printf("(DEBUG)%f %f %d\n",motorPowerDifference,AdjustmentRatio,motorPowerAlternateRatio);  
  printf("(DEBUG)%f %f\n",initialMotorPower-motorPowerDifference,initialMotorPower+motorPowerDifference);    
  motor(2,initialMotorPower-motorPowerDifference);    
  motor(3,initialMotorPower+motorPowerDifference);
}

int wallabyTurn(int direction, int degree){
  mrp(0,1000,degree*20*direction*-1);  
  mrp(1,1000,degree*20*direction);  
  mrp(2,1000,degree*20*direction*-1);  
  mrp(3,1000,degree*20*direction);  
  msleep(19*degree);  
  return EXIT_SUCCESS;
}
int wallabyTurnWithoutServoDown(int direction, int degree){  
  printf("%d --- %d",(int)(degree*13.33*direction*-1),(int)(degree*13.33*direction));  
  mrp(0,1000,(int)(degree*14*direction*-1));  
  mrp(1,1000,(int)(degree*14*direction));  
  mrp(2,1000,(int)(degree*14*direction*-1));  
  mrp(3,1000,(int)(degree*14*direction));  
  msleep(19*degree);  
  return EXIT_SUCCESS;
}
