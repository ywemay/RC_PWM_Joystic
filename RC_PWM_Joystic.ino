#include "Joystick.h"

byte PIN_THROTTLE = 2;
byte PIN_YAW = 3;
byte PIN_PITCH = 7;
byte PIN_ROLL = 8;
 
int value;
 
void setup() {
  pinMode(PIN_THROTTLE, INPUT);
  pinMode(PIN_YAW, INPUT);
  pinMode(PIN_PITCH, INPUT);
  pinMode(PIN_ROLL, INPUT);
  Joystick.begin();
}
 
void loop() {
  value = map(pulseIn(PIN_THROTTLE, HIGH), 1000, 2000, 0, 255);
  //Joystick.setThrottle(value < 0 ? 0 : (value > 255 ? 255 : value));
  Joystick.setThrottle(value < 0 ? 0 : (value > 255 ? 255 : value));
  
  value = map(pulseIn(PIN_YAW, HIGH), 1000, 2000, 0, 256);
  Joystick.setRudder(value < 0 ? 0 : (value > 255 ? 255 : value));

  value = map(pulseIn(PIN_PITCH, HIGH), 1000, 2000, -127, 127);
  Joystick.setZAxis(value < -127 ? -127 : (value > 127 ? 127 : value));
  
  value = map(pulseIn(PIN_ROLL, HIGH), 1000, 2000, -127, 127);
  Joystick.setXAxis(value < -127 ? -127 : (value > 127 ? 127 : value));
  Joystick.sendState();

}
