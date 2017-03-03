Coding Goals For Qingdao No.2 Middle School Enginnering Technology Magnet Team Botball 2017 Team
========================================================
Hi, I am axmmisaka, who mainly do the coding stuff in our group. Here, I want to set some coding goals, which may make our programs more readable, stable and easy-to-change.
I will use specfic examples to illustrate my idea.
Basic goals are listed below:

1. Use a version control system, such as Git or SVN for a better cooperation.
--------------------------------------------
Here, we will use Git as our control system, and specially, we created a private repo on Github to share files and code together. This file will also be found on the Github repo.

2. Use good indentation, good naming and annotation to make the code clearer.
-------------------------------------
All coding members in our team is training for computer olimpyiads, which needs speed when coding - but botball don't really need speed, it needs the code to be more readable and reconizable internationally. 
Admittedly, every person has his or her own coding style, and keeping it is not a bad thing, just don't mess up the code and make it like the IOCCC competition.
For example, we should code like this:
```c
//This function is completed by axmmisaka in May 2017.//
int FocusRobotUsingCamera(int velocity, int position){//Move the robot, and make it face the color block in a certain distance.
    int distance = position + camera();
    /*statements.....*/
    RunMotor(LEFT ,  velocity);//Run left motor
    RunMotor(RIGHT, -velocity);//Run right motor, reverse
    return EXIT_SUCCESS;
}
```
And not this:
```c
//shexiangji zhao xiaoqiu//
int roll(int a,int b){//sudu he weizhi
    int d=b+camera();
    //statements
    run(0,a);run(0,b);return(0);}
```
    
2. Use functions to organize programs.
---------------------------------
In order to make our program as tiny as possible, in order to make the wallaby run faster, and in order to let our program to be more organized, we should use functions to organize our program, instead of just stacking codes in one function.
For example, we should code like this:
```c
int CheckBallSituation(bool picture){
    if(digital_1==127 && picture){//what happens when this is true
        //do a lot of things
        return EXIT_SUCCESS;
    }
    else 
        return EXIT_FAILURE;
}

int main(void){
//a lot of codes...
picture = fetch(1,0);
printf("%s",CheckBallSituation()?"Success":"Failed");
//a lot of codes...
picture = fetch(1,0);
if(CheckBallSituation()){
    //foos and bars....
    }
}
```
And not this:
```c
int main(void){
//a lot of codes...
picture = fetch(1,0);
if(digital_1==127 && picture){
        //do a lot of things
        printf("SUCCESS");
    }
    else 
        printf("FAILED");
//a lot of codes...
picture = fetch(1,0);
if(digital_1==127 && picture){
//foos and bars....
    }
}
```

3.Use #define to name some useful constants instead using pale numbers
----------------------
This will make the code more readable, and avoid making mistakes when sleepy.
For example, use more this:
```c
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
#define FRONT 1
#define BACK -1

void LeftMotorMoveForwardRightBackward(int velocity){
    motor(LEFT_MOTOR, velocity*FRONT);
    motor(RIGHT_MOTOR, velocity*BACK);
}
```
And less this:
```c
void LeftMotorMoveForwardRightBackward(int velocity){
    motor(0, velocity);
    motor(1, -velocity);
}
```

4.Use parameters to combine functions together
---------------------------
Less functions makes the program's ANSI function declaration looks much better.
For example, this:
```c
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
void MoveMotor(int position){
    motor(position, -50);
}
int main(void){
    MoveMotor(LEFT_MOTOR);
    MoveMotor(RIGHT_MOTOR);
}
```
Looks much better than this, when the functions are longer than that shown in example:
```c
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
void MoveLeftMotor(int position){
    motor(LEFT_MOTOR, -50);
}
void MoveRightMotor(int position){
    motor(RIGHT_MOTOR, -50);
}
int main(void){
    MoveLeftMotor();
    MoveRightMotor();
}
```


Advanced coding goals includes:
----------------------
- Use less or no pointer
Pointer is good, but it may destroy the wallaby and south pole. No good!
- Release all code in 2019 under GPLv3
Do something for the open source community!
