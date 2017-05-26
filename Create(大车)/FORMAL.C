//coded by C6H12O6

#include <kipr/botball.h>

void tl(float x)	//turn left
{
	create_drive_direct(-200,200);
    msleep((930.0/90.0)*x);
    create_stop();
}

void tr(float x)	//turn right
{
	create_drive_direct(200,-200);
    msleep((930.0/90.0)*x);
    create_stop();
}

void run(int dis)	//forward,dis(mm)
{
	create_drive_direct(500,500);
	msleep(dis*20);
	create_stop();
	return;
}

void fd(int dis)	//forward,dis(mm)
{
	create_drive_direct(250,270);
	msleep(dis*40);
	create_stop();
	return;
}

void fd2(int dis)	//forward,dis(mm)
{
	create_drive_direct(250,270);
	msleep(dis*40);
	create_stop();
	return;
}

void slow_fd(int dis)
{
    create_drive_direct(100,100);
    msleep(dis*100);
    create_stop();
    return;
}

void bk(int dis)	//back,dis(mm)
{
	create_drive_direct(-242,-260);
	msleep(dis*40);
	create_stop();
	return;
}

void bk2(int dis)	//back,dis(mm)
{
	create_drive_direct(-239,-260);
	msleep(dis*40);
	create_stop();
	return;
}

void bk3(int dis)	//back,dis(mm)
{
	create_drive_direct(-200,-215);
	msleep(dis*50);
	create_stop();
	return;
}

void bk4(int dis)	//back,dis(mm)
{
	create_drive_direct(-210,-270);
	msleep(dis*40);
	create_stop();
	return;
}

void run_bk(int dis)
{
    create_drive_direct(-500,-500);
    msleep(dis*20);
    create_stop(); 
    return;
}

void slow_bk(int dis)
{
    create_drive_direct(-60,-60);
    msleep(dis*165);
    create_stop();
    return;
}

void xiao_zhun()
{
    while(!get_create_lbump()/*&&!get_create_rbump()*/)
    {
        create_drive_direct(100,105);
        msleep(200);
    }
    create_stop();
}   

void rsgjhyq()
{
    while(analog(0)>=500)
//    {
//		printf("%d\n",analog(0));
        msleep(100);
//    }
}

int main()
{
    int i;
	create_connect();
    msleep(1000);
	
	create_full();
	
    enable_servo(0);
   	enable_servo(1);
    enable_servo(2);
    
    msleep(1000);
    
    set_servo_position(0,2047);
    set_servo_position(1,1850);
    msleep(1000);
    set_servo_position(2,0);
    
    printf("ready for match\n");
    
    rsgjhyq();
    shut_down_in(117);
    i=0;
    while(i<=1800)
    {
        i+=5;
        set_servo_position(2,i);
        msleep(1);
    }
    fd2(73);
    
    while(i>=1320)
    {
        i-=1;
        set_servo_position(2,i);
        msleep(4);
    }
    msleep(500);
    tl(60);
    bk(10);
    tl(70);
    bk(50);
    tl(90);
    bk(30);
    fd(16);
    tr(90);
    
    set_servo_position(0,580);
    set_servo_position(1,720);
    bk3(50);
    set_servo_position(1,1900);
   	set_servo_position(0,1200);
    bk(30);
    slow_bk(15);
    set_servo_position(1,720);
    set_servo_position(0,1900);
    fd(15);
    tr(90);
    bk(15);
    tl(45);
    bk(13);
    msleep(500);
    while(i>=845)
    {
        i-=5;
        set_servo_position(2,i);
        msleep(1);
    }
    fd(13);
    tr(45);
    fd(20);
    tl(90);
    bk(10);
    slow_bk(20);
    
    while(i>=5)
    {
        i-=5;
        set_servo_position(2,i);
        msleep(1);
    }
    
    set_servo_position(1,720);
    fd(26);
    tr(90);
    bk(52);
    slow_bk(20);
    fd(20);
    tr(180);
    set_servo_position(0,587);	//ready for catching the middle grass
    set_servo_position(1,720);
    
    bk(41);
    set_servo_position(1,1900);	//got it
    
    msleep(500);
    
    i=710;
    create_drive_direct(50,50);
    while(i<=1200)			//rise it slowly
    {
        i+=1;
   		set_servo_position(0,i);
        msleep(3);
    }
    create_stop();
    fd(37);					//move to the gu cang
    
    tl(90);
    bk(8);
    
    i=1200;
    while(i>=587)			//put it down
    {
        i-=1;
   		set_servo_position(0,i);
        msleep(1);
    }
    
    i=1900;
    while(i>=720)			//put it down
    {
        i-=1;
   		set_servo_position(1,i);
        msleep(3);
    }
    
    slow_fd(5);
    set_servo_position(0,1650);	//rise up the catcher
    set_servo_position(1,1850);
    xiao_zhun();
    bk(40);
    tl(90);				//make sure the position is right
    slow_bk(25);
    
    //second step
    
    fd(20);
    tr(180);
    set_servo_position(0,587);	//ready for catching the left grass
    set_servo_position(1,720);
    bk(39);
    msleep(500);
    set_servo_position(1,1900);	//got it
    msleep(500);
    i=710;
    
    create_drive_direct(50,50);
    while(i<=1500)			//rise it slowly
    {
        i+=1;
   		set_servo_position(0,i);
        msleep(3);
    }
    create_stop();
    
    fd(32);
    tl(90);
    fd(10);					//move to the gu cang

    i=1500;
    while(i>=800)			//put it down
    {
        i-=1;
   		set_servo_position(0,i);
        msleep(1);
    }
    
    i=1900;
    while(i>=720)			//put it down
    {
        i-=1;
   		set_servo_position(1,i);
        msleep(3);
    }
    
    slow_fd(5);
    set_servo_position(0,1650);
    set_servo_position(1,1850);
    xiao_zhun();
    bk(10);
    
    tl(90);			//jiao_zhun
    slow_bk(10);
    
    //third step
    
    fd(40);
    tl(90);
    slow_bk(20);
    fd(5);
    tl(90);
    set_servo_position(0,587);	//ready for the right grass
    set_servo_position(1,720);
    bk4(17);
    msleep(500);
    set_servo_position(1,1900);
    msleep(500);
    i=690;
    
    create_drive_direct(20,20);
    while(i<=1700)			//rise it slowly
    {
        i+=1;
   		set_servo_position(0,i);
        msleep(3);
    }
    create_stop();
    tr(70);
    slow_bk(15);
    fd(70);
    tl(90);
    bk(20);
    slow_bk(17);
    fd(10);
    tr(168);
    bk(20);
    tl(10);
    i=1700;
    while(i>=1030)			//put it down
    {
        i-=1;
   		set_servo_position(0,i);
        msleep(2);
    }
    
    i=1900;
    while(i>=720)			//put it down
    {
        i-=1;
   		set_servo_position(1,i);
        msleep(3);
    }
    
	create_disconnect();
    
    while(1);
    return 0;
}
