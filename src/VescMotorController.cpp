#include "VescMotorController.h"

/// <summary>
/// Initialise the controller for use with the Wizibot Shield
/// </summary>
void VescMotorController::initWithWizibotShield()
{
    _leftMotor.attach(WIZIBOT_LEFT_MOTOR_PIN);
    _rightMotor.attach(WIZIBOT_RIGHT_MOTOR_PIN);

	// Initialise the VESC by setting it to stop for 500ms
	stop();
	delay(500);
}

/// <summary>
/// Initialise the controller to use th specified PWM pins
/// </summary>
void VescMotorController::init(int leftMotorPin, int rightMotorPin)
{
  _leftMotor.attach(leftMotorPin);
  _rightMotor.attach(rightMotorPin);

  // Initialise the VESC by setting it to stop for 500ms
  stop();
  delay(500);
}

/// <summary>
/// Set the motor throttle for both motors to the same values (e.g forwards or backwards motion)
/// </summary>
void VescMotorController::setThrottle(int throttlePerc)
{
	// Clamp values to expected values
  if(throttlePerc > 100) throttlePerc = 100;
  if(throttlePerc < -100) throttlePerc = -100;

  _leftMotorSpeed = throttlePerc;
  _rightMotorSpeed = throttlePerc;
  
  apply();
}

/// <summary>
/// Set the throttle for both left and right motors independantly (for Turns)
/// </summary>
void VescMotorController::setThrottle(int leftThrottle, int rightThrottle)
{
  // Clamp the values to expected min/max ranges
  if(leftThrottle > 100) leftThrottle = 100;
  if(leftThrottle < -100) leftThrottle = -100;
  if(rightThrottle > 100) rightThrottle = 100;
  if(rightThrottle < -100) rightThrottle = -100;

  _leftMotorSpeed = leftThrottle;
  _rightMotorSpeed = rightThrottle;
  
  apply();
}

/// <summary>
/// Stop both motors
/// </summary>
void VescMotorController::stop()
{
  _leftMotorSpeed = 0;
  _rightMotorSpeed = 0;

  apply();
}

/// <summary>
/// Private function to apply the throttle to the required motor controller servos
// </summary>
void VescMotorController::apply()
{
  _leftMotor.writeMicroseconds(map(_leftMotorSpeed, -100, 100, MAX_REVERSE_PWM, MAX_FORWARD_PWM));
  _rightMotor.writeMicroseconds(map(_rightMotorSpeed, -100, 100, MAX_REVERSE_PWM, MAX_FORWARD_PWM));     
}