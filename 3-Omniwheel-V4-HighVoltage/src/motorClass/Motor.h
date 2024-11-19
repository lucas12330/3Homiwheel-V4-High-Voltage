#include <Arduino.h>

class Motor
{
public:
  Motor(int RPWM, int LPWM);
  ~Motor();

  void changePins(int RPWM, int LPWM);
  int setSpeed(int speed);

private:
  int m_RPWM;
  int m_LPWM;
};
