#pragma config(Motor,  port2,           WheelR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           WheelL,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ClimbArm,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Scissors,  		 tmotorVex393_MC29, openLoop)

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
  bDisplayCompetitionStatusOnLcd = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

task autonomous()
{
  // ..........................................................................
  // Autonomous is 15 seconds
  // ..........................................................................

  // Remove this function call once you have "real" code.
  //AutonomousCodePlaceholderForTesting();
		//wait1Msec(2000);						// Robot waits for 2000 milliseconds before executing program

	// Move forward at full power for 3 seconds (extension function)
	  motor[WheelR] = 127;		  // Motor on port2 is run at full (127) power forward
		motor[WheelL]  = 127;		  // Motor on port3 is run at full (127) power forward
		wait1Msec(2825);			    // Robot runs previous code for 3000 milliseconds (3s) before moving on
		motor[WheelR] = 0;
		motor[WheelL] = 0;
		motor[Scissors]  = 127;		    // Motor on port5 is run at full (127) power to extend the Scissors
		wait1Msec(1000);			        // Robot runs previous code to operate Scissors
		motor[Scissors]  = -127;		  // Motor on port5 is run at full (-127) power backwards
		wait1Msec(1000);							// Retract Scissors
		motor[Scissors]  = 0;					// Turn off motor
		motor[WheelR] = 80;           // Turn 120 degrees
		motor[WheelL] = -127;         // Turn 120 degrees in combination with right motor
		wait1Msec(1550);
		motor[WheelL] = 0;
		motor[WheelR] = 0;
		motor[WheelL] = 50;
		motor[WheelR] = 50;
		wait1Msec(180);
		motor[WheelL] = 0;
		motor[WheelR] = 0;
	//	motor[WheelR] = 80;
	//	motor[WheelL] = -270;
	//	wait1Msec(100);
	//	motor[WheelL] = 0;
	//  motor[WheelR] = 0
		motor[ClimbArm] =  127;
		wait1Msec(2500);
		motor[ClimbArm] = 0; //Posibbility of changing it so that the high-hang goes lower
	/*
		//Alternative.. Start in backwards position.
		//drive forward(backward) to fence
		//raise lift and lower
		//move backwards
		//turn 180 degrees
		//extend DNA
		//wait 1 second
	*/
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  Duration is 1:45   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
 		motor[port3] = vexRT[Ch2];
  	motor[port2] = vexRT[Ch3];


 		if(vexRT[Btn6U] == 1) //Extend Up
  {
  		motor[ClimbArm] = 127;
  }
  	else if(vexRT[Btn6D] == 1) //Retract Down
  {
  		motor[ClimbArm] = -127;
  }
  	else
  {
  		motor[ClimbArm] = 0;

  	if(vexRT[Btn5U] == 1) //Up
  {
  		motor[Scissors] = 127;
  }
  	else if(vexRT[Btn5D] == 1) //Down
  {
  		motor[Scissors] = -127;
  }
  	else
  {
  	motor[Scissors] = 0;
  }
}

  }
}
