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

void slow_tl(float x)	//turn left
{
	create_drive_direct(-100,100);
    msleep((930.0/45)*x);
    create_stop();
}

void slow_tr(float x)	//turn right
{
	create_drive_direct(100,-100);
    msleep((930.0/45)*x);
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
	create_drive_direct(-200,-200);
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
    while(!get_create_lbump()&&!get_create_rbump())
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

void motor_drive()
{
    while(1)
    {
        motor(0,1);
        msleep(200);
        motor(0,-1);
        msleep(200);
    }
}

int main()
{
    int i;
    thread tid;
	create_connect();
    msleep(1000);
	
	create_full();
    enable_servo(2);
    
    msleep(1000);
    set_servo_position(2,0);
    
    printf("ready for match\n");
    
    //rsgjhyq();
    shut_down_in(117);
    i=0;
    msleep(1000);
    create_drive_direct(-270,-270);
    motor(0,20);
    msleep(1000);
    create_stop();
    slow_bk(15);
    motor(0,20);
    msleep(1700);
    tid=thread_create(motor_drive);
    thread_start(tid);
    slow_tr(30);
    slow_tl(45);
    slow_tr(45);
    slow_tl(30);
    thread_destroy(tid);
    motor(0,-20);
    msleep(2000);
    tid=thread_create(motor_drive);
    thread_start(tid);
    slow_bk(10);
    fd(20);
    tl(90);
    slow_bk(20);
    fd(170);
    xiao_zhun();
    bk(10);
    tl(90);
    fd(30);
    
    thread_destroy(tid);
    return 0;
}
