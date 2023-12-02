/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       bossman                                                   */
/*    Created:      20/10/2023, 13:03:42                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FR                   motor         4               
// FL                   motor         5               
// BL                   motor         6               
// BR                   motor         7               
// Controller1          controller                    
// LaunchSwitch         limit         A               
// Pult                 motor         9               
// Lift                 motor         1               
// LiftSwitch           limit         H               
// Intake               motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "robot-config.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  BL.spin(forward);
  FL.spin(forward);
  FR.spin(forward);
  BR.spin(forward);
  Pult.setVelocity(50, percent);
  Lift.setVelocity(50, percent);
  Lift.setMaxTorque(100, percent);
  Pult.setStopping(brake);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Pult.spin(forward);
  waitUntil(LaunchSwitch.pressing());
  Pult.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

 

void usercontrol(void) {
  // User control code here, inside the loop

  while (1) {
    BL.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent), percent);
    FL.setVelocity(Controller1.Axis3.position(percent) + Controller1.Axis4.position(percent), percent);
    FR.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent), percent);
    BR.setVelocity(Controller1.Axis3.position(percent) - Controller1.Axis4.position(percent), percent);

    //if(!LaunchSwitch.pressing() || Con1.ButtonA.pressing())
    //  Pult.spin(forward);
    //else
    //  Pult.stop();
    if(Controller1.ButtonA.pressing()) 
    {
      Lift.spin(reverse);
    }
    else if(LiftSwitch.pressing()) 
      Lift.stop();
    else if (Controller1.ButtonB.pressing())
      Lift.spin(forward);
    else 
    {
      Lift.setStopping(brake);
      Lift.stop();
    }
    if(Controller1.ButtonX.pressing())
      Intake.spin(forward);
    else if(Controller1.ButtonY.pressing())
      Intake.stop();
      
    if(Controller1.ButtonR2.pressing())
    {
      Pult.spinFor(forward, 1, turns);
    }


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
