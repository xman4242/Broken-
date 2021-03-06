#ifndef ROBOT_h
#define ROBOT_h

#include <YETI_YUKON.h>
#include <STATE.h>

#include <XBOXRECV.h>

#include <YUKON_CytronMD10.h>

#include "Subsystems\Drive.h"
#include "Subsystems\Lift.h"
#include "Subsystems\Claw.h"
#include "Subsystems\BuddyBot.h"

#include "Autonomous\AUTONOMOUS.h"

class ROBOT
{
  public:
    ROBOT(YETI_YUKON &rYukon);

    void Setup();
    void Loop();

    YETI_YUKON &Yukon;

    STATE State;

    //Motors
    YUKON_CytronMD10 DriveRight;
    YUKON_CytronMD10 DriveLeft;
    YUKON_CytronMD10 LiftMotor;
    YUKON_CytronMD10 ClawMotor;
    YUKON_CytronMD10 BuddyBotLift;

    //Subsystems
    DRIVE Drive;
    LIFT Lift;
    CLAW Claw;
    BUDDYBOT   BuddyBot;
    AUTONOMOUS Auton;

    //USB Items
    USB Usb;
    
    XBOXRECV Xbox;
    
    
   

    //PIN Declarations
    static const int _DriveRightPWM = 0;
    static const int _DriveRightDir = 14;
    static const bool _DriveRightReversed = true;
        
    static const int _DriveLeftPWM = 1;
    static const int _DriveLeftDir = 17;
    static const bool _DriveLeftReversed = false;
        
    static const int _LiftMotorPWM = 2;
    static const int _LiftMotorDir = 21;
    static const bool _LiftMotorReversed = false;
        
    static const int _ClawMotorPWM = 3;
    static const int _ClawMotorDir = 22;
    static const bool _ClawMotorReversed = false;
        
    static const int _BuddyBotLiftPWM = 4;
    static const int _BuddyBotLiftDir = 26 ;
    static const bool _BuddyBotLiftReversed = false;
        

    static const uint8_t _Button0 = 0;
    static const uint8_t _LEDBuiltIn = 25;
    static const uint8_t _AutonLightSensor = 1;
    static const uint8_t LeftEncoderPin1 = 26;
    static const uint8_t LeftEncoderPin2 = 27;

    static const uint16_t _AutonLightSensorThreshold = 3000; //Value 0 - 4095
    int WheelDiam = 4;
    float WheelCirc = (3.1415) * (WheelDiam);

  private:
      long _NextDisplayMillis = 0;
      long _NextMotorControllerWriteMillis = 0;
      long _NextGetPrevSpeed = 0;
};
#endif

/*class Encoder;

    //Read the Encoders
    void EncRead() 
    {
        long oldPosition = 0;
        Encoder myEnc(26, 27);
        long NewLeftPos = myEnc.read();
    if (NewLeftPos != oldPosition) 
        oldPosition = NewLeftPos;
        Serial.println(NewLeftPos);
    }*/

