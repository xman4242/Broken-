
#include "DRIVE.h"
#include "ROBOT.h"

DRIVE::DRIVE(ROBOT &refRobot) : Robot(refRobot)
{
}

void DRIVE::Loop()
{
    //Only Run Command Code When Valid
    if (!CmdTimedOut() && CmdIsRunning())
    {
        if (CmdName() == "ForAsync")
        {
            Robot.State.DriveRightSpeed = _CmdDriveRightSpeed;
            Robot.State.DriveLeftSpeed = _CmdDriveLeftSpeed;
            while (CmdUpdatePercent(millis()))
            {
                delay(20);
            }
        }
    }
    Robot.State.DriveRightSpeed = _OIDriveRightSpeed;
    Robot.State.DriveLeftSpeed = _OIDriveLeftSpeed;

    delay(20);
}
       
void DRIVE::OISetSpeed(int16_t DriveRightSpeed,int16_t DriveLeftSpeed)
{
    _OIDriveRightSpeed = DriveRightSpeed;
    _OIDriveLeftSpeed = DriveLeftSpeed;
}

bool DRIVE::ForInches(long Inches, int16_t DriveRightSpeed, int16_t DriveLeftSpeed, uint8_t HoldUntilPercent)
{       //Takes Inches and turns it into millis
        float RealSpeed = (DriveRightSpeed * 300);
        float RealSpeed2 = (RealSpeed)/255;
        float RotationsPerSec = RealSpeed2/60;
        float InchesPerSec = RotationsPerSec* 12.56; 
        float Sec = Inches/InchesPerSec;
        int durationMS = (Sec)*1000;
        Robot.Drive.ForAsync(durationMS, DriveRightSpeed, DriveLeftSpeed, HoldUntilPercent);

    bool retVal = ForInches(Inches, DriveRightSpeed, DriveLeftSpeed, HoldUntilPercent);
    while (CmdPercentComplete() < HoldUntilPercent && retVal)
    {
        delay(20);
    }
    return retVal;
}

bool DRIVE::ForInches(long Inches, int16_t DriveRightSpeed, int16_t DriveLeftSpeed)
{
    //Takes Inches and turns it into millis
    float RealSpeed = (DriveRightSpeed * 300);
    float RealSpeed2 = (RealSpeed)/255;
    float RotationsPerSec = RealSpeed2/60;
    float InchesPerSec = RotationsPerSec* 12.56; 
    float Sec = Inches/InchesPerSec;
    int durationMS = (Sec)*1000;
    _CmdDriveRightSpeed = DriveRightSpeed;
    _CmdDriveLeftSpeed = DriveLeftSpeed;
    

    bool retVal = CmdStart("ForInches", millis(), millis() + durationMS, durationMS + 500);

    return retVal;
}

bool DRIVE::Turn(long Degrees, int16_t DriveRightSpeed, int16_t DriveLeftSpeed, uint8_t HoldUntilPercent)
{
    float RobotCirc = 48.67;
    int FractionOfTurn = 360/Degrees;
    float InchestoTurn = RobotCirc/FractionOfTurn;
    abs(DriveRightSpeed);
    float RealSpeed = (DriveRightSpeed * 300);
    float RealSpeed2 = (RealSpeed)/255;
    float RotationsPerSec = RealSpeed2/60;
    float InchesPerSec = RotationsPerSec* 12.56; 
    float Sec = InchestoTurn/InchesPerSec;
    int durationMS = (Sec)*1000;
    Robot.Drive.ForAsync(durationMS, DriveRightSpeed, DriveLeftSpeed, HoldUntilPercent);
    bool retVal = Turn(Degrees, DriveRightSpeed, DriveLeftSpeed, HoldUntilPercent);
    while (CmdPercentComplete() < HoldUntilPercent && retVal)
    {
        delay(20);
    }
    return retVal;
}

bool DRIVE::Turn(long Degrees, int16_t DriveRightSpeed, int16_t DriveLeftSpeed)
{   
    float RobotCirc = 48.67;
    int FractionOfTurn = 360/Degrees;
    float InchestoTurn = RobotCirc/FractionOfTurn;
    abs(DriveRightSpeed);
    float RealSpeed = (DriveRightSpeed * 300);
    float RealSpeed2 = (RealSpeed)/255;
    float RotationsPerSec = RealSpeed2/60;
    float InchesPerSec = RotationsPerSec* 12.56; 
    float Sec = InchestoTurn/InchesPerSec;
    int durationMS = (Sec)*1000;
    _CmdDriveRightSpeed = DriveRightSpeed;
    _CmdDriveLeftSpeed = DriveLeftSpeed;
    

    bool retVal = CmdStart("Turn", millis(), millis() + durationMS, durationMS + 500);

    return retVal;
}

bool DRIVE::ForAsync(long durationMS, int16_t DriveRightSpeed,int16_t DriveLeftSpeed, uint8_t HoldUntilPercent)
{
    bool retVal = ForAsync(durationMS, DriveRightSpeed,DriveLeftSpeed);
    while (CmdPercentComplete() < HoldUntilPercent && retVal)
    {
        delay(20);
    }

    return retVal;
}




bool DRIVE::ForAsync(long durationMS, int16_t DriveRightSpeed,int16_t DriveLeftSpeed)
{
    _CmdDriveRightSpeed = DriveRightSpeed;
    _CmdDriveLeftSpeed = DriveLeftSpeed;
    

    bool retVal = CmdStart("ForAsync", millis(), millis() + durationMS, durationMS + 500);

    return retVal;
}
