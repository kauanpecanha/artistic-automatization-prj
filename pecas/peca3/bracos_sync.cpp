#include <Arduino.h>

/* CODE FOR 1/4 STEPS, 800 STEPS PER REVOLUTION, 1:1 RESOLUTION */

// Enable pin
#define ARM1_EN 22
#define FOREARM1_EN 25
#define ARM2_EN 28
#define FOREARM2_EN 31
#define ARM3_EN 34
#define FOREARM3_EN 37
#define ARM4_EN 40
#define FOREARM4_EN 43

// Direction & Step pin
#define ARM1_DIR 23
#define ARM1_STP 24
#define ARM2_DIR 29
#define ARM2_STP 30
#define ARM3_DIR 35
#define ARM3_STP 36
#define ARM4_DIR 41
#define ARM4_STP 42

// Direction & Step pin
#define FOREARM1_DIR 26
#define FOREARM1_STP 27
#define FOREARM2_DIR 32
#define FOREARM2_STP 33
#define FOREARM3_DIR 38
#define FOREARM3_STP 39
#define FOREARM4_DIR 44
#define FOREARM4_STP 45

// Delay between steps
const int delayTime = 200;

// Resolution relation
const int RELATION_ARM = 10;
const int RELATION_FOREARM = 10;

void setup()
{
  pinMode(ARM1_DIR, OUTPUT);
  pinMode(ARM2_DIR, OUTPUT);
  pinMode(ARM1_STP, OUTPUT);
  pinMode(ARM2_STP, OUTPUT);
  pinMode(ARM3_DIR, OUTPUT);
  pinMode(ARM3_STP, OUTPUT);
  pinMode(ARM4_DIR, OUTPUT);
  pinMode(ARM4_STP, OUTPUT);
  pinMode(FOREARM1_DIR, OUTPUT);
  pinMode(FOREARM2_DIR, OUTPUT);
  pinMode(FOREARM1_STP, OUTPUT);
  pinMode(FOREARM2_STP, OUTPUT);
  pinMode(FOREARM3_DIR, OUTPUT);
  pinMode(FOREARM3_STP, OUTPUT);
  pinMode(FOREARM4_DIR, OUTPUT);
  pinMode(FOREARM4_STP, OUTPUT);
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
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW); 
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);
  }
}
