#include <Arduino.h>
#include <Servo.h>

/// <summary>
/// Available Sockets for the Vesc control
/// </summary>
enum WizibotMotorSocket { M1, U1, U2 };

/// <summary>
/// Vesc motor controller for use with either the Wizibot Shield or utilising two PWM pins on an Arduino board
/// </summary>
class VescMotorController
{
  public:
	
    /// <summary>
    /// Initialise the controller for use with the Wizibot Shield
	/// The Wizibot shield sockets are supported on the following
	/// M1 - All Arduino Boards
	/// U1 - Arduino Mega
	/// U2 - Arduino Mega
    /// </summary>
    void initWithWizibotShield(WizibotMotorSocket socket);
    
    /// <summary>
    /// Initialise the controller to use th specified PWM pins
    /// </summary>
    void init(int leftMotorPin, int rightMotorPin);

    /// <summary>
    /// Set the motor throttle for both motors to the same values (e.g forwards or backwards motion)
    /// </summary>
    void setThrottle(int throttlePercent);

    /// <summary>
    /// Set the throttle for both left and right motors independantly (for Turns)
    /// </summary>
    void setThrottle(int leftThrottle, int rightThrottle);

    /// <summary>
    /// Stop both motors
    /// </summary>
    void stop();


  protected:

    /// <summary>
    /// Currently set left motor speed
    /// </summary> 
    int _leftMotorSpeed;

    /// <summary>
    /// Currently set right motor speed
    /// </summary>
    int _rightMotorSpeed;

    /// <summary>
    /// Wizibot Left Motor PWM Pin on the Arduino
    /// </summary>
    const int WIZIBOT_LEFT_MOTOR_PIN = 3;

    /// <summary>
    /// Wizibot right motor PWM pin on the Arduino
    /// </summary>
    const int WIZIBOT_RIGHT_MOTOR_PIN = 5;

	/// <summary>
	/// Wizibot right motor PWN Pin for the U1 socket
	/// </summary>
	const int WIZIBOT_RIGHT_MOTOR_U1_PIN = 7;

	/// <summary>
	/// Wizibot left motor PWN Pin for the U1 socket
	/// </summary>
	const int WIZIBOT_LEFT_MOTOR_U1_PIN = 6;

	/// <summary>
	/// Wizibot right motor PWN Pin for the U2 socket
	/// </summary>
	const int WIZIBOT_RIGHT_MOTOR_U2_PIN = 8;

	/// <summary>
	/// Wizibot right motor PWN Pin for the U1 socket
	/// </summary>
	const int WIZIBOT_LEFT_MOTOR_U2_PIN = 9;

    /// <summary>
    /// Maximum PWM signal for full speed ahead
    /// </summary>
    const int MAX_FORWARD_PWM = 2000;

    /// <summary>
    /// Minimum PWM signal for full reverse speed
    /// </summary>
    const int MAX_REVERSE_PWM = 1000;

    /// <summary>
    /// Left Motor controller (PPM through servo)
    /// </summary>
    Servo _leftMotor;

    /// <summary>
    /// Right motor controller (PPM through servo)
    /// </summary>
    Servo _rightMotor;
    
    /// <summary>
    /// Apply existing motor throttle settings
    /// </summary>
    void apply();
};
