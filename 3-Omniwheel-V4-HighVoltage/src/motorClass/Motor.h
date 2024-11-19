#pragma once
#include <Arduino.h>



class Motor
{
private:
  // Instanciation de l'enum class
  enum class rotation{RELEASE, FORWARD, BACKWARD};
  // Pin Pwm des deux sens d'un seul moteur
  int m_RPWM;
  int m_LPWM;

  // Sens de rotation du moteur
  rotation m_rotation;

  // Limite informatique de la vitesse des moteur
  int m_speedLimit;


public:
  Motor(int RPWM, int LPWM, int SpeedLimit);
  ~Motor();
  // Permet la modification des pins d'un moteur
  void changePins(int RPWM, int LPWM);
  // Permet la modification de la vitesse
  int setSpeed(int Speed);
  //  Permet la modification du sens de rotation
  void setRotation(rotation Rotation);



};
