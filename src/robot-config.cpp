#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FR = motor(PORT4, ratio18_1, false);
motor FL = motor(PORT5, ratio18_1, true);
motor BL = motor(PORT6, ratio18_1, false);
motor BR = motor(PORT7, ratio18_1, true);
controller Controller1 = controller(primary);
limit LaunchSwitch = limit(Brain.ThreeWirePort.A);
motor Pult = motor(PORT9, ratio36_1, true);
motor Lift = motor(PORT1, ratio36_1, false);
limit LiftSwitch = limit(Brain.ThreeWirePort.H);
motor Intake = motor(PORT10, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}