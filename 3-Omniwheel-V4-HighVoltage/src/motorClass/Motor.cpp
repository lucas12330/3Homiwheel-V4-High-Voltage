#pragma once
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

// le constructeur a appelé si pas envie de définir la vitesse max(auto 255)
Motor::Motor(int RPWM, int LPWM)
{
  this->m_speedLimit = 255;
  this->m_RPWM = RPWM;
  this->m_LPWM = LPWM;
  pinMode(this->m_RPWM, OUTPUT);
  pinMode(this->m_LPWM, OUTPUT);
}

Motor::~Motor()
{
  setSpeed(0, RELEASE);
}

void Motor::changePins(int RPWM, int LPWM)
{
  this->m_RPWM = RPWM;
  this->m_LPWM = LPWM;
  pinMode(this->m_RPWM, OUTPUT);
  pinMode(this->m_LPWM, OUTPUT);
}


// Speed entre 0 et 255, le sens de rotation est donc géré via une méthode externe
int Motor::setSpeed(int speed, rotation Rotation)
{
  this->m_rotation = Rotation;
  switch (this->m_rotation)
  {
  case rotation::RELEASE :
    analogWrite(this->m_RPWM, 0);
    analogWrite(this->m_LPWM, 0);
    return 0;
  case rotation::FORWARD :
    analogWrite(this->m_RPWM, speed);
    analogWrite(this->m_LPWM, 0);
    return 0;
  case rotation::BACKWARD :
    analogWrite(this->m_RPWM, 0);
    analogWrite(this->m_LPWM, speed);
    return 0;
  }
  return -1; // pas bon paramètre, erreur
}
