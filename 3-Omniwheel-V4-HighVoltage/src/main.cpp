#include <Arduino.h>
#include <PS2X_lib.h>
#include <motorClass/Motor.h>

// Instanciation des moteur
Motor m1(2, 3);
Motor m2(4, 5);
Motor m3(6, 7);
void setup() {

}

void loop() {
    for (int i = 0; i <= 255; i++){
        m1.setSpeed(i, FORWARD);
        m2.setSpeed(i, FORWARD);
        m3.setSpeed(i, FORWARD);
        delay(10);
    }
    for (int i = 255; i >= 0; i--){
        m1.setSpeed(i, FORWARD);
        m2.setSpeed(i, FORWARD);
        m3.setSpeed(i, FORWARD);
        delay(10);
    }


}

