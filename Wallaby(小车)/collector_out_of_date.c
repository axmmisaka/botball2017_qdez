//Usage of collector after going up
//Created by Charlie5381

#include <kipr/botball.h>
int i=200;
int t=1;
int main(){
    /*Init the servo (collector)*/
  	enable_servo(3);
  	set_servo_position(3,200);
  	//Init end
  	//
  	motor(0,50);
  	motor(1,50);
  	msleep(10000);
  	while (t<=3){
      	motor(0,-50);
      	motor(1,-50);
      	msleep(1000);
        i=200;
      	set_servo_position(3,i);
      	t++;
      	motor(0,0);
      	motor(1,0);
  		while (i<=1500){
   	 		i++;
   	   		set_servo_position(3,i);
          	msleep(5);
    		}
      	i=1000;
      	motor(0,50);
      	motor(1,50);
      	msleep(1500);
      	motor(0,0);
      	motor(1,0);
      	set_servo_position(3,i);
      	msleep(1000);
      	i=1500;
      	set_servo_position(3,i);
      	motor(0,-50);
      	motor(1,-50);
      	msleep(500);
      	motor(0,0);
      	motor(1,0);
  	}
    return 0;
}
