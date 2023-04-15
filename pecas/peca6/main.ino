#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <RotaryEncoder.h>
#define PPR 29
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
const int DT = 2;
const int CLK = 3;

// potentiometer pin
const int pot = A0;
float vel = 0;

// declaration of encoder object
RotaryEncoder encoder(DT, CLK, RotaryEncoder::LatchMode::TWO03);

// variable to angle control
float angle = 0;

// ON/OFF codes
const int codeON = 0xAA1;  // on
const int code1 = 0xAA2;   // first sequence signal
const int code2 = 0xAA3;   // second sequence signal
const int code3 = 0xAA4;   // third sequence signal
const int codeOFF = 0xAA5; // off

// IR receive parameters
const int IR = 9;
IRrecv IrReceiv(IR);
decode_results result;

void moveTo(float now, float target) // function to rotate the motor to specific angles
{
  vel = (analogRead(pot) / 4); // velocity setting

  if (target > 0)
  {
    if (now <= target)
    {
      analogWrite(LPWM, 0);
      analogWrite(RPWM, vel); // right rotation
    }
    else
    {
      stopMotor();
    }
  }
  else
  {
    if (now >= target)
    {
      analogWrite(RPWM, 0);
      analogWrite(LPWM, vel); // left rotation
    }
    else
    {
      stopMotor();
    }
  }
}

void stopMotor() // function to stop the motor rotation
{
  analogWrite(RPWM, 0);
  analogWrite(RPWM, 0);
}

void getAngle() // printing data function
{
  static int pos = 0;
  encoder.tick();
  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    angle = (float)newPos / PPR * 360;
    Serial.print("Actual angle: ");
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
  IrReceiv.enableIRIn();
}

void loop()
{
  if (IrReceiv.decode(&result))
  {
    Serial.print(result.bits);
    Serial.print(": ");
    Serial.println(result.value, HEX);
    IrReceiv.resume();
  }
  switch (result.vawlue)
  {
    case codeON:
      // 1st signal is received
      while (angle < 90)
      {
        getAngle();
        moveTo(angle, 90);
      }
      delay(30000);

    case code1:
      // 2nd signal is received
      while (angle > -90)
      {
        getAngle();
        moveTo(angle, -90);
      }
      delay(30000);

    case code2:
      // 3rd signal is received
      while (angle < 90)
      {
        getAngle();
        moveTo(angle, 90);
      }
      delay(30000);

    case code3:
      // 5th signal is received, 4th signal is ignored
      getAngle();
      stopMotor();
      delay(30000);

    case codeOFF:
      stopMotor();

    default:
      stopMotor();
      Serial.println("ERROR");
      break;
  }
}
