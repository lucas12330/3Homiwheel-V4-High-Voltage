#include <Arduino.h>
#include <PS2X_lib.h>
#include <Motor.h>
#include <math.h>

// Initialisation des variables
int joyL_x = 0;
int joyL_y = 0;

int joyR_x = 0;
int joyR_y = 0;

// Instaciation de la connexion manette
PS2X man;

// Instanciation des moteur
Motor m1(2, 3);
Motor m2(4, 5);
Motor m3(6, 7);

// Initialisation des constantes
enum class motor{
  M1,
  M2, 
  M3,
};

// Initialisation des fonction
void move(int speedRotation, int speed, int motor);
void equal(int val);
// Fonction permettant de map tout les joysticks
void mapJoystick();
// Fonction pour aquérir les valeur des joystick
int getJoystick(bool rol);
void setSpeedAll(int Speed, rotation Rotation);

byte error = 0;
void setup() {
    Serial.begin(9600);
    error = man.config_gamepad(21, 2, 20, 3);
    while ( error != 0){
        error = man.config_gamepad(21, 2, 20, 3);
        delay(100);
        Serial.println("Erreur de configuration de la manette");
    }
    Serial.println("Connexion réussi");
}

void loop() {
    man.read_gamepad();

    // Lecture du joystick gauche
    joyL_x = man.Analog(PSS_LX);
    joyL_y = man.Analog(PSS_LY);

    // Lecture du joystick droit
    joyR_x = man.Analog(PSS_RX);
    joyR_y = man.Analog(PSS_RY);

    mapJoystick();
    equal(10);
    move(joyL_x, joyR_y, 1);
    Serial.println(joyL_x);


}

void move(int speedRotation, int speed, int motor){
if (speed < -255 || speed > 255){
// Permet de sécuriser et d'empecher le passage de n'importe quelle donné en dehor du domaine de définition
  } else {
    //
    if (speed  != 0){
      if (speed < 0){
        switch(motor){
          case 1:
            m3.setSpeed(abs(speed), BACKWARD);
            m2.setSpeed(abs(speed), FORWARD);
            if (speedRotation<0){
              m1.setSpeed(abs(speedRotation), FORWARD);
            } else {
              m1.setSpeed(abs(speedRotation), BACKWARD);
            }
            break;
          
          case 2:
            m3.setSpeed(abs(speed), BACKWARD);
            m1.setSpeed(abs(speed), FORWARD);
            if (speedRotation<0){
              m2.setSpeed(abs(speedRotation), FORWARD);
            } else {
              m2.setSpeed(abs(speedRotation), BACKWARD);
            }
            break;

          case 3:
            m3.setSpeed(abs(speed), BACKWARD);
            m2.setSpeed(abs(speed), FORWARD);
            if (speedRotation<0){
              m3.setSpeed(abs(speedRotation), FORWARD);
            } else {
              m3.setSpeed(abs(speedRotation), BACKWARD);
            }
            break;
        }


      } else {
        if (speed > 0){
          m1.setSpeed(abs(speed), FORWARD);
          m2.setSpeed(abs(speed), BACKWARD);
          if (speedRotation<0){
            m3.setSpeed(abs(speedRotation), FORWARD);
          } else {
            m3.setSpeed(abs(speedRotation), BACKWARD);
          }
        }

      }
    } else {
      if(speedRotation < 0){
        setSpeedAll(abs(speedRotation), FORWARD);
      } else {
        setSpeedAll(abs(speedRotation), BACKWARD);
      }

    }
  }
}
void setSpeedAll(int Speed, rotation Rotation){
  m1.setSpeed(Speed, Rotation);
  m2.setSpeed(Speed, Rotation);
  m3.setSpeed(Speed, Rotation);
}

void mapJoystick(){
  joyL_x = map(joyL_x, 0, 255, -255, 255);
  joyL_y = map(joyL_y, 0, 255, -255, 255);
  joyR_x = map(joyR_x, 0, 255, -255, 255);
  joyR_y = map(joyR_y, 0, 255, -255, 255);
}

void equal(int val){
  if(joyL_x < val && -val<joyL_x){
    joyL_x = 0;
  }
  if(joyL_y<val && -val<joyL_y){
    joyL_y = 0;
  }
  if(joyR_x<val && -val<joyR_x){
    joyR_x = 0;
  }
  if(joyR_y<val && -val<joyR_y){
    joyR_y = 0;
  }
}