# P2 Upload a Code Review Document 

## Introduction 
Although this is the second year our school participate in International Botball Touranment, 3 of 5 of our team members are participating Botball for the first time. In the national qualifier we do have 5 people who can master programming, but only one of them will come with us to the United States, and he is also the weakest one among those five, Yimo Xu, i.e. axmmisaka.  
The two robots, create and wallaby as we simply call them, will finish objectives in different areas: create focus on big objects, such as hay stacks and water containers, and wallaby focus on small objects on upper level, mostly poms.  
Yimo Xu(github:axmmisaka) and Renhao Xue(github:moriatia) finished most new programs finished after national qualifier. Yimo Xu focus on programming wallaby and reviewing create's code, and Renhao Xue focus on programming create and reviewing wallaby's code. Xiao Yu and Gonghao Zhang will perform review for all code, make sure there is no leak.

## Best Practices Checklist
Before national qualifier, axmmisaka wrote down some coding goals, which you can find in the github repository. 
- [x] Use a version control system for better cooperation
- [x] Functions and macros are used to organize and shorten code
- [x] Code contains comments for explaining functions, arguments, varibles and statements.
- [x] All names of functions and varibles are following camelCase rule
- [ ] Code use parameters to combine functions together
- [x] Code should be formatted and in well indent
Before the qualfier, were expecting that most functions will have its "opposite" one, for example, if a function can move the robot forward, then the opposite one could make it backward - so to shorten the program, we could have adopted this style: 
```c
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
#define FORWARD 1
#define BACKWARD -1
//committed to Github 04/jul/17
//Move the wallaby from starting area onto the ramp.
//Return values: success - EXIT_SUCCESS
//Testing:
//Place the robot 2.5cm horizontally from the downright edge of the starting area
//Usage: wallabyMoveToRamp(FORWARD|BACKWARD, 75);
int wallabyMoveToRamp(int direction, int power){
  motor(MOTOR_LEFT,power * direction);
  motor(MOTOR_RIGHT,power * direction);
  msleep(1730);
  ao();
  return EXIT_SUCCESS;
}
```
But soon we found that this style will not cause much effect - most functions will only be used once, so a function's "opposite" one seldom becomes useful. During the qualifier, we decided not to adopt this style.
