//coded by axmmisaka
#include "kipr/botball.h"
int CreateInit(){
	while(create_connect()) {
			msleep(400);
		}
	console_clear();
	create_full();
	return EXIT_SUCCESS;
}

int main(void){
	CreateInit();
	printf("Press Play button to continue.\n");
	printf("Battery is now %d mAh with a full of %d mAh",get_create_battery_charge(),get_create_battery_capacity());
	while(!get_create_play_button());
	console_clear();
	printf("Moving and Sensor test");
	while(1){
	create_drive_strait();
		if(get_create_rbump()){
			create_stop();
			set_create_normalized_angle(0);
			set_create_total_angle(0);
			create_spin_CW(20);
				while(set_create_normalized_angle()<=90);
			create_stop();
		}
	if(get_create_play_button())
		break;
	}
}
	
