using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FR;
extern motor FL;
extern motor BL;
extern motor BR;
extern controller Controller1;
extern limit LaunchSwitch;
extern motor Pult;
extern motor Lift;
extern limit LiftSwitch;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );