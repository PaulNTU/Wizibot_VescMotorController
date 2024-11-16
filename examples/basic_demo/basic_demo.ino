// Include the VescMotorController library
#include <VescMotorController.h>

// Create a motor Controller object to control the object
VescMotorController _motorController;

void setup() {
  // If you are using the wizibot shield with socket M1, U1 or U2 use this command. 
  // Note: U1 and U2 is not supported on Arduino Uno as both pins on the sockets don't support PWM (~)
  _motorController.initWithWizibotShield(WizibotMotorSocket::M1);

  // Otherwise use this one (Left motor pin, Right motor pin). Pins need to be a PWM ~ pin
  //_motorController.init(3, 5);
}

void loop() {
  
  _motorController.setThrottle(100);

  // Move forwards at max speed
  _motorController.setThrottle(100);
  delay(2000);

  // Reverse at max speed
  _motorController.setThrottle(-100);
  delay(2000);

  // Turn on the spot to the right
  _motorController.setThrottle(50, -50);
  delay(2000);

  // Turn on the spot to the left
  _motorController.setThrottle(-50, 50);
  delay(2000);

  // Stop both motors
  _motorController.stop();
  delay(1000);
}
