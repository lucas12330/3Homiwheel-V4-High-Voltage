#include "Motor.h"
#include <Arduino.h>
#include <math.h>

Motor::Motor(int RPWM, int LPWM, int SpeedLimit)
{
  this->m_speedLimit = SpeedLimit;
  this->m_RPWM = RPWM;
  this->m_LPWM = LPWM;
  pinMode(this->m_RPWM, OUTPUT);
  pinMode(this->m_LPWM, OUTPUT);
}

Motor::~Motor()
{
  setSpeed(0);
}

void Motor::changePins(int RPWM, int LPWM)
{
  this->m_RPWM = RPWM;
  this->m_LPWM = LPWM;
  pinMode(this->m_RPWM, OUTPUT);
  pinMode(this->m_LPWM, OUTPUT);
}
void Motor::setRotation(rotation Rotation)
{
  this->m_rotation = Rotation;
}

// Speed entre 0 et 255, le sens de rotation est donc géré via une méthode externe
int Motor::setSpeed(int speed)
{
  if(this->m_rotation == rotation::RELEASE)
  {
    return 0;
  } else if(this->m_rotation == rotation::FORWARD){
     analogWrite(this->m_RPWM, speed);
     analogWrite(this->m_LPWM, 0);
    } else if (this-> m_rotation == rotation::BACKWARD){
      analogWrite(this-> m_LPWM, speed);
      analogWrite(this->m_RPWM, 0);
    }

}