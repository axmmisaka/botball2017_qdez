#include <kipr/botball.h>
#define SERVO_LIFT 0
#define SERVO_CATCH 1
float elapsedTime;

void phase1(){
  enable_servo(SERVO_LIFT);
  enable_servo(SERVO_CATCH);
  set_servo_position(SERVO_LIFT,2200);
  set_servo_position(SERVO_CATCH,2200);
  elapsedTime = seconds()+4.5;
  motor(0,50);
  motor(1,100);
  while(seconds()<elapsedTime){
  }
  //motor(0,20);
  //motor(1,20);
  //elapsedTime = seconds()+0.3;
  //while(seconds()<elapsedTime){
  //}
  ao();
  set_servo_position(SERVO_CATCH,720);
  msleep(2000);
}
void phase2(){
  elapsedTime = seconds()+4.5;
  motor(0,-50);
  motor(1,-100);
  while(seconds()<elapsedTime){
  }
  elapsedTime = seconds()+6;
  motor(0,100);
  motor(1,100);
  while(seconds()<elapsedTime){
  }
}
int main()
{
  phase1();
  phase2();
    printf("Hello World\n");
    return 0;
}
