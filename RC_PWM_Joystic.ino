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

/*#include <PinChangeInt.h>
 
#define PIN_T 5 // we could choose any pin
#define PIN_Y 6
#define PIN_P 7
#define PIN_R 8

//#define
 
volatile int pwm_value = 0;
volatile int prev_time = 0;
uint8_t latest_interrupted_pin;
 
void rising()
{
  latest_interrupted_pin=PCintPort::arduinoPin;
  PCintPort::attachInterrupt(latest_interrupted_pin, &falling, FALLING);
  prev_time = micros();
}
 
void falling() {
  latest_interrupted_pin=PCintPort::arduinoPin;
  PCintPort::attachInterrupt(latest_interrupted_pin, &rising, RISING);
  pwm_value = micros()-prev_time;
  Serial.print(latest_interrupted_pin);
  Serial.print(":");
  Serial.println(pwm_value);
}
 
void setup() {
  pinMode(PIN_T, INPUT); digitalWrite(PIN_T, HIGH);
  pinMode(PIN_Y, INPUT); digitalWrite(PIN_Y, HIGH);
  pinMode(PIN_P, INPUT); digitalWrite(PIN_P, HIGH);
  pinMode(PIN_R, INPUT); digitalWrite(PIN_R, HIGH);
  Serial.begin(115200);
  PCintPort::attachInterrupt(PIN_T, &rising, RISING);
  PCintPort::attachInterrupt(PIN_Y, &rising, RISING);
  PCintPort::attachInterrupt(PIN_P, &rising, RISING);
  PCintPort::attachInterrupt(PIN_R, &rising, RISING);
}
 
void loop() { }
*/
