#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <RotaryEncoder.h> // Library to use the rotary encoder KY-040
#include <IRremote.hpp> // Library to receive IR signals

#define PPR 29 // Constant for the rotary encoder angle
#define RPWM 5
#define LPWM 6

/*
  Pins connected to aduino

  IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
  IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
  IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
  IBT-2 pin 8 (GND) to Arduino's GND
  IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/

// rotary encoder pins
const int pin1 = 2;
const int pin2 = 3;
RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);

// potentiometer pin (velocity control)
const int pot = A0;
float vel = 0;

// angle variables
float tgtangle = 30;
float angle = 0;

// IR receiver parameters
const int IR = 9;
IRrecv IrReceiv(IR);
decode_results result;

// ON/OFF codes
const int codeON = 0xAA1; // on
const int codeOFF = 0xAA4; // off

// function in use to move the sculpture 30 degrees / -30 degrees 
void moveTo(float now, float target)
{
  vel = (analogRead(pot) / 4);
  if (target > 0)
  {
    if (now <= target)
    {
      analogWrite(LPWM, 0);
      analogWrite(RPWM, vel);
    }
    else
    {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
      delay(200);
      tgtangle = -30;
    }
  }
  else
  {
    if (now >= target)
    {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, vel);
    }
    else
    {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, 0);
      delay(200);
      tgtangle = 30;
    }
  }
}

// function in use to stop the sculpture
void stopMottor()
{
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

// function that obtain the angle at the moment
void getAngle()
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    angle = (float)newPos / PPR * 360;
    Serial.print("Desired angle: ");
    Serial.print(tgtangle);
    Serial.print(" || Actual angle: ");
    Serial.print(angle);
    Serial.print(" || Direction: ");
    Serial.print((int)(encoder.getDirection()));
    Serial.print(" || RPM: ");
    Serial.println((int)(encoder.getRPM()));
    pos = newPos;
  }
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (IrReceiv.decode(&result)) // If any signal are detected
  {
    Serial.print(result.bits);
    Serial.print(": ");
    Serial.println(result.value, HEX);
    IrReceiv.resume();
  }
  switch (result.value) // Stop or Move the sculpture according to the IR code
  {
  case codeON:
    getAngle();
    Serial.println("Move");
    moveTo(angle, tgtangle);
    break;
  case codeOFF:
    Serial.println("Stop");
    stopMottor();
    break;
  default:
    Serial.println("ERROR");
    stopMottor();
    break;
  }
}
