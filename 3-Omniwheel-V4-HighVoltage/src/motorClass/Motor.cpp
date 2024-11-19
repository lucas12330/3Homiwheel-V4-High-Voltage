#include "Motor.h"

Motor::Motor(int RPWM, int LPWM)
{
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

int Motor::setSpeed(int speed)
{
  if (speed > 0 && speed < 127)
  {
    analogWrite(this->m_RPWM, speed);
    analogWrite(this->m_LPWM, 0);
    return 1;
  }
  else if (speed < 0 && speed > -127)
  {
    speed = -speed;
    analogWrite(this->m_RPWM, 0);
    analogWrite(this->m_LPWM, speed);
    return -1;
  }
  else
  {
    analogWrite(this->m_RPWM, 0);
    analogWrite(this->m_LPWM, 0);
    return 0;
  }
}