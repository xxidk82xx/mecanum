#include "vex.h"

using namespace vex;

extern brain Brain;

// VEXcode devices

extern controller Con1;

extern motor FL;
extern motor FR;
extern motor BR;
extern motor BL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );