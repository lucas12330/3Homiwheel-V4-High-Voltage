#include <Arduino.h>
#include <PS2X_lib.h>
#include <motorClass/Motor.h>

// Instanciation des moteur
Motor m1(2, 3);
Motor m2(4, 5);
Motor m3(6, 7);
void setup() {
    m1.setRotation(rotation::FORWARD);
    m2.setRotation(rotation::FORWARD);
    m3.setRotation(rotation::BACKWARD);
}

void loop() {
    for (int i = 0; i <= 255; i++){
        m1.setSpeed(i);
        m2.setSpeed(i);
        m3.setSpeed(i);
        delay(10);
    }
    for (int i = 255; i >= 0; i--){
        m1.setSpeed(i);
        m2.setSpeed(i);
        m3.setSpeed(i);
        delay(10);
    }


}

