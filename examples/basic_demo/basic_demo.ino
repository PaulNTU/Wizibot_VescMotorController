// Incluse the VescMotorController library
#include <VescMotorController.h>

// Create a motor Controller object to control the object
VescMotorController _motorController;

void setup() {
  // If you are using the wizibot shield use this initialisation command:
  _motorController.initWithWizibotShield();

  // Otherwise use this one (Left motor pin, Right motor pin)
  _motorController.init(3, 5);
}

void loop() {

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
