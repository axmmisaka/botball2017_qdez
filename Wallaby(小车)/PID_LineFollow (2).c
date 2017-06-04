#include <kipr/botball.h>
const int power=50;
int cz=0;
int er=0;
int pc=(2100+3900)/2;
float t;
float kp=0.05;
int dh;
void pid()
{
	er=dh-pc;
  	cz=kp*er;
  	motor(0,power-cz);motor(1,power+cz);
}
int main()
{
  	t=seconds()+3;
  	while(seconds()<t)
    {
motor(0,70);
motor(1,70);
    }//Climb onto the ramp
  	dh=analog(0);
  	t+=10;
  	while (seconds()<t)
    {
  printf("%d\n",dh);
   dh=analog(0);
pid();
    }
  	t+=2;
  	while (seconds()<t)
    {
motor(0,power);
      	motor(1,power);
    }
    return 0;
}
