#include <kipr/botball.h>

void motor(int p){
    motor(0, 100*p);
		motor(1, 100*p);
}

int main(void){
    while(1){
        if(a_button_clicked()){
            motor(1);
        }
        if(b_button_clicked()){
            motor(-1);
        }
        if(c_button_clicked()){
            motor(0);
            ao();
        }
    }
    return 0;
}
