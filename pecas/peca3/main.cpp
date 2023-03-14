#include <Arduino.h>

/* CODE FOR 1/4 STEPS, 800 STEPS PER REVOLUTION, 1:1 RESOLUTION */

// Enable pin
#define EN 8

// Direction & Step pin
#define ARM1_DIR 5
#define ARM1_STP 2

// Direction & Step pin
#define FOREARM1_DIR 7
#define FOREARM1_STP 4

// Delay between steps
const int delayTime = 200;

// Resolution relation
const int resolution = 1;

void setup()
{
  pinMode(ARM1_DIR, OUTPUT);
  pinMode(ARM1_STP, OUTPUT);
  pinMode(FOREARM1_DIR, OUTPUT);
  pinMode(FOREARM1_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}

void loop()
{

  digitalWrite(ARM1_DIR, 1);
  for (int i = 0; i < 800 * resolution; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(ARM1_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(100);

  digitalWrite(FOREARM1_DIR, 1);
  for (int i = 0; i < 900 * resolution; i++)
  {
    digitalWrite(FOREARM1_STP, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(FOREARM1_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(250);

  digitalWrite(FOREARM1_DIR, 0);
  for (int i = 0; i < 100 * resolution; i++)
  {
    digitalWrite(FOREARM1_STP, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(FOREARM1_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(100);

  digitalWrite(ARM1_DIR, 0);
  for (int i = 0; i < 100 * resolution; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(ARM1_STP, LOW);
    delayMicroseconds(delayTime);
  }
  delay(1000);

  digitalWrite(ARM1_DIR, 1);
  for (int i = 0; i < 100 * resolution; i++)
  {
    digitalWrite(ARM1_STP, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(ARM1_STP, LOW);
    delayMicroseconds(delayTime);
  }
}