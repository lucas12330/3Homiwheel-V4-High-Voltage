#pragma once
#include <Arduino.h>
#include <math.h>

// Instanciation de l'enum class
enum rotation{RELEASE, FORWARD, BACKWARD};

class Motor
{
private:

  // Pin Pwm des deux sens d'un seul moteur
  int m_RPWM;
  int m_LPWM;

  // Sens de rotation du moteur
  rotation m_rotation;

  // Limite informatique de la vitesse des moteur
  int m_speedLimit;


public:
  Motor(int RPWM, int LPWM, int SpeedLimit);
  Motor(int RPWM, int LPWM);

  ~Motor();
  // Permet la modification des pins d'un moteur
  void changePins(int RPWM, int LPWM);
  // Permet la modification de la vitesse
  int setSpeed(int Speed, rotation Rotation);
};
