// ------------------------------------------------------------------------------------
// bibliotecas da peça 3 com receptor infravermelho
#include <Arduino.h>
#include <RotaryEncoder.h>
#include <IRremote.hpp>

/* CODE FOR 1/4 STEPS, 800 STEPS PER REVOLUTION, 1:1 RESOLUTION */

// Arm & Forearm 1 EN - DIR - PUL(STP)
#define ARM1_EN 22
#define ARM1_DIR 23
#define ARM1_STP 24
#define FOREARM1_EN 25
#define FOREARM1_DIR 26
#define FOREARM1_STP 27

// Arm & Forearm 2 EN - DIR - PUL(STP)
#define ARM2_EN 28
#define ARM2_DIR 29
#define ARM2_STP 30
#define FOREARM2_EN 31
#define FOREARM2_DIR 32
#define FOREARM2_STP 33

// Arm & Forearm 3 EN - DIR - PUL(STP)
#define ARM3_EN 34
#define ARM3_DIR 35
#define ARM3_STP 36
#define FOREARM3_EN 37
#define FOREARM3_DIR 38
#define FOREARM3_STP 39

// Arm & Forearm 4 EN - DIR - PUL(STP)
#define ARM4_EN 40
#define ARM4_DIR 41
#define ARM4_STP 42
#define FOREARM4_EN 43
#define FOREARM4_DIR 44
#define FOREARM4_STP 45

// Delay between steps == velocity
const int delayTime = 200;

// Resolution relation
const int RELATION_ARM = 10;
const int RELATION_FOREARM = 10;

// Rotary encoder pins
#define DT_A1 = 2;
#define CLK_A1 = 3;
#define DT_FA1 = 4;
#define CLK_FA1 = 5;
RotaryEncoder encoder_A1(DT_A1, CLK_A1, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA1(DT_FA1, CLK_FA1, RotaryEncoder::LatchMode::TWO03);

#define DT_A2 = 6;
#define CLK_A2 = 7;
#define DT_FA2 = 8;
#define CLK_FA2 = 9;
RotaryEncoder encoder_A2(DT_A2, CLK_A2, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA2(DT_FA2, CLK_FA2, RotaryEncoder::LatchMode::TWO03);

#define DT_A3 = 10;
#define CLK_A3 = 11;
#define DT_FA3 = 12;
#define CLK_FA3 = 13;
RotaryEncoder encoder_A3(DT_A3, CLK_A3, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA3(DT_FA3, CLK_FA3, RotaryEncoder::LatchMode::TWO03);

#define DT_A4 = 14;
#define CLK_A4 = 15;
#define DT_FA4 = 16;
#define CLK_FA4 = 17;
RotaryEncoder encoder_A4(DT_A4, CLK_A4, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA4(DT_A4, CLK_FA4, RotaryEncoder::LatchMode::TWO03);

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

void getPosition_A2()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_A2.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | ARM2 position = ");
  Serial.print(pos);
  Serial.print(" |");
}
void getPosition_FA2()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_FA2.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | FOREARM2 position = ");
  Serial.print(pos);
  Serial.print(" |");
}

void getPosition_A3()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_A3.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | ARM3 position = ");
  Serial.print(pos);
  Serial.print(" |");
}
void getPosition_FA3()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_FA3.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | FOREARM3 position = ");
  Serial.print(pos);
  Serial.print(" |");
}

void getPosition_A4()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_A4.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | ARM4 position = ");
  Serial.print(pos);
  Serial.print(" |");
}
void getPosition_FA4()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder_FA4.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | FOREARM4 position = ");
  Serial.print(pos);
  Serial.print(" |");
}

void setup()
{
  pinMode(ARM1_DIR, OUTPUT);
  pinMode(ARM1_STP, OUTPUT);
  pinMode(ARM2_DIR, OUTPUT);
  pinMode(ARM2_STP, OUTPUT);
  pinMode(ARM3_DIR, OUTPUT);
  pinMode(ARM3_STP, OUTPUT);
  pinMode(ARM4_DIR, OUTPUT);
  pinMode(ARM4_STP, OUTPUT);
  pinMode(FOREARM1_STP, OUTPUT);
  pinMode(FOREARM1_DIR, OUTPUT);
  pinMode(FOREARM2_STP, OUTPUT);
  pinMode(FOREARM2_DIR, OUTPUT);
  pinMode(FOREARM3_STP, OUTPUT);
  pinMode(FOREARM3_DIR, OUTPUT);
  pinMode(FOREARM4_STP, OUTPUT);
  pinMode(FOREARM4_DIR, OUTPUT);
  pinMode(ARM1_EN, OUTPUT);
  pinMode(ARM2_EN, OUTPUT);
  pinMode(ARM3_EN, OUTPUT);
  pinMode(ARM4_EN, OUTPUT);
  pinMode(FOREARM1_EN, OUTPUT);
  pinMode(FOREARM2_EN, OUTPUT);
  pinMode(FOREARM3_EN, OUTPUT);
  pinMode(FOREARM4_EN, OUTPUT);
  digitalWrite(ARM1_EN, LOW);
  digitalWrite(ARM2_EN, LOW);
  digitalWrite(ARM3_EN, LOW);
  digitalWrite(ARM4_EN, LOW);
  digitalWrite(FOREARM1_EN, LOW);
  digitalWrite(FOREARM2_EN, LOW);
  digitalWrite(FOREARM3_EN, LOW);
  digitalWrite(FOREARM4_EN, LOW);
}

void loop()
{
  getPosition_A1();
  getPosition_FA1();
  Serial.println();
  getPosition_A2();
  getPosition_FA2();
  Serial.println();
  getPosition_A3();
  getPosition_FA3();
  Serial.println();
  getPosition_A4();
  getPosition_FA4();
  Serial.println();
  
  digitalWrite(ARM1_DIR, 1);
  digitalWrite(ARM2_DIR, 1);
  digitalWrite(ARM3_DIR, 1);
  digitalWrite(ARM4_DIR, 1);
  for (int i = 0; i < 800 * RELATION_ARM; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
    getPosition_A2();
    getPosition_FA2();
    Serial.println();
    getPosition_A3();
    getPosition_FA3();
    Serial.println();
    getPosition_A4();
    getPosition_FA4();
    Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(100);

  digitalWrite(FOREARM1_DIR, 1);
  digitalWrite(FOREARM2_DIR, 1);
  digitalWrite(FOREARM3_STP, 1);
  digitalWrite(FOREARM4_STP, 1);
  for (int i = 0; i < 900 * RELATION_FOREARM; i++)
  {
    digitalWrite(FOREARM1_STP, HIGH);
    digitalWrite(FOREARM2_STP, HIGH);
    digitalWrite(FOREARM3_STP, HIGH);
    digitalWrite(FOREARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
    getPosition_A2();
    getPosition_FA2();
    Serial.println();
    getPosition_A3();
    getPosition_FA3();
    Serial.println();
    getPosition_A4();
    getPosition_FA4();
    Serial.println();
    digitalWrite(FOREARM1_STP, LOW);
    digitalWrite(FOREARM2_STP, LOW);
    digitalWrite(FOREARM3_STP, LOW);
    digitalWrite(FOREARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(250);

  digitalWrite(FOREARM1_DIR, 0);
  digitalWrite(FOREARM2_DIR, 0);
  digitalWrite(FOREARM3_STP, 0);
  digitalWrite(FOREARM4_STP, 0);
  for (int i = 0; i < 100 * RELATION_FOREARM; i++)
  {
    digitalWrite(FOREARM1_STP, HIGH);
    digitalWrite(FOREARM2_STP, HIGH);
    digitalWrite(FOREARM3_STP, HIGH);
    digitalWrite(FOREARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
    getPosition_A2();
    getPosition_FA2();
    Serial.println();
    getPosition_A3();
    getPosition_FA3();
    Serial.println();
    getPosition_A4();
    getPosition_FA4();
    Serial.println();
    digitalWrite(FOREARM1_STP, LOW);
    digitalWrite(FOREARM2_STP, LOW);
    digitalWrite(FOREARM3_STP, LOW);
    digitalWrite(FOREARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(100);

  digitalWrite(ARM1_DIR, 0);
  digitalWrite(ARM2_DIR, 0);
  digitalWrite(ARM3_STP, 0);
  digitalWrite(ARM4_STP, 0);
  for (int i = 0; i < 100 * RELATION_ARM; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
    getPosition_A2();
    getPosition_FA2();
    Serial.println();
    getPosition_A3();
    getPosition_FA3();
    Serial.println();
    getPosition_A4();
    getPosition_FA4();
    Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(1000);

  digitalWrite(ARM1_DIR, 1);
  digitalWrite(ARM2_DIR, 1);
  digitalWrite(ARM3_STP, 1);
  digitalWrite(ARM4_STP, 1);
  for (int i = 0; i < 100 * RELATION_ARM; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
    getPosition_A2();
    getPosition_FA2();
    Serial.println();
    getPosition_A3();
    getPosition_FA3();
    Serial.println();
    getPosition_A4();
    getPosition_FA4();
    Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
}
