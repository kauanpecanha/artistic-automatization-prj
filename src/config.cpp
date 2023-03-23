#include <Arduino.h>
#include <RotaryEncoder.h>

/* Code for discover the relation between Arm & Forearm pulley */

// Arm & Forearm 1 EN - DIR - PUL(STP)
#define ARM1_EN 22
#define ARM1_DIR 23
#define ARM1_STP 24
#define FOREARM1_EN 25
#define FOREARM1_DIR 26
#define FOREARM1_STP 27

// Rotary encoder pins
#define DT_A1 = 2;
#define CLK_A1 = 3;
#define DT_FA1 = 4;
#define CLK_FA1 = 5;
RotaryEncoder encoder_A1(DT_A1, CLK_A1, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA1(DT_FA1, CLK_FA1, RotaryEncoder::LatchMode::TWO03);

void getPosition_A1()
{
    static int pos = 0;
    encoder.tick();
    int newPos = encoder_A1.getPosition();
    if (pos != newPos)
    {
        pos = newPos;
    }
    Serial.print(" | ARM1 position = ");
    Serial.print(pos);
    Serial.print(" |");
}
void getPosition_FA1()
{
    static int pos = 0;
    encoder.tick();
    int newPos = encoder_FA1.getPosition();
    if (pos != newPos)
    {
        pos = newPos;
    }
    Serial.print(" | FOREARM1 position = ");
    Serial.print(pos);
    Serial.print(" |");
}

void loop()
{
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
}
