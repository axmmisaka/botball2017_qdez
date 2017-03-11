//axmmisaka
//20170228
//gplv3

#include <kipr/botball.h>
#define WHEEL_LEFT 0
#define WHEEL_RIGHT 1
#define BACK 65530
#define FRONT 65531
#define LEFT 65532
#define RIGHT 65533

int turn(int direction){
    if(direction == LEFT){
        mrp(WHEEL_LEFT,-500,-1000);
        mrp(WHEEL_RIGHT,500,1000);
    }
    if(direction == RIGHT){
        mrp(WHEEL_RIGHT,-500,-1000);
        mrp(WHEEL_LEFT,500,1000);
    }
    return EXIT_SUCCESS;
}

int WhereIs(int ObjectCenterX){
    return (ObjectCenterX>55&&ObjectCenterX<65)?0:(ObjectCenterX>=65)?1:-1;
}

int camera(void){
    int p;
        camera_update();
        if(get_object_count(0)){
            p = WhereIs(get_object_center_x(0,0));
            if(p==0) printf("object is in center");
            if(p==-1){
                printf("object is on left, adjusting");
                turn(LEFT);
            }
            if(p==1){
                printf("object is on right, adjusting");
                turn(RIGHT);
            }
    }
        else printf("No object can be found.");
    return EXIT_SUCCESS;
}
int main(void){
    camera_open(LOW_RES);
    while(1){
    camera();
    while(!b_button_clicked());
    }
}
