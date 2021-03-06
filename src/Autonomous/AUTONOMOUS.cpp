#include "AUTONOMOUS.h"
#include "ROBOT.h"

AUTONOMOUS::AUTONOMOUS(ROBOT &refRobot) : Robot(refRobot)
{
    _MaxProgramNumber = 4;
}

void AUTONOMOUS::Loop()
{
    if (_AutonARMED)
    {
        if (Robot.State.AutonLightSensorActive)
        {
            LaunchQueued();
        }
    }

    if (_RunningAuton == "Auton1") ExecAuton1();
    else if(_RunningAuton == "Auton2") ExecAuton2();
    else if(_RunningAuton == "Auton3") ExecAuton3();
    else if(_RunningAuton == "Auton4") ExecAuton4();

     _RunningAuton = "";
    delay(20);
}
//You need to travel about 0975 ms to go a whole tile 
void AUTONOMOUS::ExecAuton1()
{
    //Hits low flag and drives on the platform
    Robot.Drive.ForAsync(3000, 100, 100, 100);
    Robot.Drive.ForAsync(4300, -100, -100, 100);
    Robot.Drive.ForAsync(1500, -100, 100, 100);
    Robot.Drive.ForAsync(2000, 255, 255, 100);

  
}
void AUTONOMOUS::ExecAuton2()
{   //Skills Auton. Will hit flag, get BuddyBot, parks
    Robot.Drive.ForAsync(3000, -100, -100, 0);
    Robot.BuddyBot.ForAsync(6600, 100, 100 );
    Robot.Drive.ForAsync(3919, 100, 100, 100);
    Robot.Drive.ForAsync(25000, 0, 0, 100);
    Robot.Drive.ForAsync(1061, 75, 75, 100);
    Robot.BuddyBot.ForAsync(3000, -100, 100);
    Robot.Drive.ForAsync(2041, 100,100,100);
    Robot.Drive.ForAsync(497, 100, -100, 100);
    Robot.Drive.ForAsync(2500, 255, 255, 100);
    

}
void AUTONOMOUS::ExecAuton3()
{
    Robot.BuddyBot.ForAsync(6495, 100, 100);
}
void AUTONOMOUS::ExecAuton4()
{   //Test Auton
    Robot.Drive.ForInches(24, 100, 100, 100);
    //Robot.Drive.Turn(360, 100, -100, 100);
}