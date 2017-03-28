///move the create from start area to the orange ball
//finished by charlie5381 and axmmisaka
#include <kipr/botball.h>

int main()
{
    create_connect();
    create_full();
    create_drive_direct(100,100);
    msleep(1750);
    printf("moving to next\n");
    create_drive_direct(-200,200);
    printf("2rollin complete\n");
    msleep(900);
    create_drive_direct(200,200);
    msleep(1750);
    create_drive_direct(0,0);
    motor(0,100);
    msleep(4000);
    return 0;
}
