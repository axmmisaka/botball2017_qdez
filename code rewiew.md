# P2 Upload a Code Review Document 

## Introduction 
Although this is the second year our school participate in International Botball Touranment, 3 of 5 of our team members are participating Botball for the first time. In the national qualifier we do have 5 people who can master programming, but only one of them will come with us to the United States, and he is also the weakest one among those five, Yimo Xu, i.e. axmmisaka. <br> 
The two robots, create and wallaby as we simply call them, will finish objectives in different areas: create focus on big objects, such as hay stacks and water containers, and wallaby focus on small objects on upper level, mostly poms.  <br> 
Yimo Xu(github:axmmisaka) and Renhao Xue(github:moriatia) finished most new programs finished after national qualifier. Yimo Xu focus on programming wallaby and reviewing create's code, and Renhao Xue focus on programming create and reviewing wallaby's code. Xiao Yu and Gonghao Zhang will perform review for all code every Saturday, make sure there is no leak. The final review is conducted in 17 Jul 2017.
## Best Practices Checklist
Before national qualifier, axmmisaka wrote down some coding goals, which you can find in the github repository. 
- [x] Use a version control system for better cooperation
- [x] Functions and macros are used to organize and shorten code
- [x] Code contains comments for explaining functions, arguments, varibles and statements.
- [x] All names of functions and varibles are following camelCase rule
- [ ] Code use parameters to combine functions together
- [x] Code should be formatted and in well indent
<br>
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


## Reliability
### Procedures
Even though all playgrounds are built in the same standard, some details may still be different and thus have an effect on robots. <br> 
To improve the create's reliability, after every single step, the create will calibrate - drive to the border and align, make sure it has a perfectly heading position. We used front collision sensor and time control to make sure the wallaby will neither miss its destination nor fall off the playground. <br> 
As for wallaby, we used several sensors since its area has more marks than create's do. Like create, we used both time control and sensor to make sure robots will not misjudge, like this:
```c
const float maximumTime = 7.0f;
const float minimumTime = 12.0f;
float elapsedTime;
while(elapsedTime <= maximumTime &&\ // did not stuck or off-position
(IRSensorValue >= MINIMUN_DISTANCE || elapsedTime >= minimumTime)){ //IR is reliable
  wallabyGoStraight();
  IRSensorValue = analog(SENSOR_IR);//update sensor value
  elapsedTime = seconds();//update time
}
```
Wallaby also used motor position counters to dertermine if slip happens, thus, as we programmed, it may auto-repair itself if needed.<br>
However, until this review is finished, we still did not meet our expectation on the errors, which is about 2 centimeter and the reality is about 5 centimeter, although it's accurate enough to finish all tasks without having any fatal problem. We will improve the accuracy by doing more tests and using more reliable algorithms to calibrate.
### The program itself
I, axmmisaka, as a ameteur programmer who has made a little improvements on Github for some opensource projects, deeply know how unrealiable these home-make projects are. To improve reliability, the program itself should not crash at first. Below are some points.<br>
- Pointers in C Programming Language is powerful, but sometimes they may be fatal, like dangling or wild pointers. Our program do not need complicated data structures, as a result, pointer is not needed, and thus we used no pointers. 
- Goto statement may be useful, but it makes the program more likely to crash, said Dijkstra. We used goto statement in national qualfier to reduce workload, but now we successfully converted them into loops and break or continue statemant.
- Global varibles may be a must, but we reduced its number to minimum. Too many global variables can make the program less realible because the cohesion will decrease, and it may have a negative effect on other local varibles.
- No undefined behaviors. The compiler provided by KIPR is pretty reliable, but it is like every compiler, unable to do anything with undefined behaviours. Thus, for some statements like printf("%d, %d",++n,frontSensorDetect(n,2)); or some woodenheaded statement like msleep(++time+++++++time++);
- Do as much code reviews as you can. Some howlers are less easy to detect and fatal, such as typing "==" as "=" or assigning a value to a constant.

# Maintainability and portability
As we use git as the version control system, it is very easy to see where the program has changed. Altough we do not commit changes too often because most of the changes are specfic values that need to be measured every time, we commit when major changes took place. Thus, if anything goes wrong, it will be very easy for us to roll back to previous version or use the diff tool to see where these problems may occur.<br>
![Commits on Github](https://github.com/axmmisaka/botball2017_qdez/blob/master/Journal(%E6%97%A5%E8%AE%B0)/QQ%E6%88%AA%E5%9B%BE20170605001426.jpg?raw=true)<br>
Some people's English is not that proficent, and they update github in Chinese.<br>

Some codes are initially written by teammates who participate in Olympiad in Informatics(like USACO), they write super-fast, but varibles are named poorly, no comments, and there's even no indentation! If any of us see such situation, we will immediately go ask him(before he forget anything) the meaning of these variable names(most are abbreviations of Chinese Pinyin or simple English words), and change the code to the most readable one. For example, in commit e8e3e49ca3d51b7308c69d09288a25902928bf0b, we changed an nearly unreadable code into a readable one without changing its core algorighm, below is the difference of this commit and previous one using diff tool:
![diff](https://github.com/axmmisaka/botball2017_qdez/blob/master/Journal(%E6%97%A5%E8%AE%B0)/QQ%E6%88%AA%E5%9B%BE20170605005138.jpg?raw=true)

As for portability, although we used some KIPR-exclusive functions, but other platforms may have sililar one. The point is, as we mentioned in the previous chapter, all codes follow ISO C-89 standard, which means, no undefined behaviors or non-fatal problems are in the program; and community's common sense, for example, return value 0 have the meaning that the function successfully exited, and value 1 does not. We also deleted all bit operations, because it could be fatal if we transform this program onto a platform that doesn't have the same architecture (e.g. x86 and x64).

# Effectiveness
The main time robots will elapse is during displacement instead of calculations in the program, but it is still very important to let the program to be effective, because an effective program is also less likely to crash.
Below are some ways we improve effectiveness:
- Use less data structures
- 避免不必要的函数调用,赋值(像strlen)
- 用无符号整数 计算快
