// --------------------------------------------------------------------------------------------
// bibliotecas do código do receptor

#include <Arduino.h>
#include <IRremote.hpp>

// --------------------------------------------------------------------------------------------
// bibliotecas do código da peca5

#include <RotaryEncoder.h>

#define RPWM 5
#define LPWM 6

// --------------------------------------------------------------------------------------------
// informações importantes da peca5

/*
  Pins connected to aduino( in english )

  IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
  IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
  IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
  IBT-2 pin 8 (GND) to Arduino's GND
  IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/

// --------------------------------------------------------------------------------------------
// variáveis importantes do receptor

const int IR = 9;
IRrecv IrReceiv(IR);
decode_results result;

const int code1 = 0xAA1;
const int code2 = 0xAA2;
const int code3 = 0xAA3;
const int code4 = 0xAA4;
const int code5 = 0xAA5;

// --------------------------------------------------------------------------------------------
// variáveis da peca5

// rotary encoder pins
const int pin1 = 2;
const int pin2 = 3;

RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);

// --------------------------------------------------------------------------------------------
// funções da peca5

void rotateMotor(bool b, int vel) /*  function to set the sense of rotation of the motor */
{
  if (b == true)
  {
    // gira para direita - rotate to the right
    analogWrite(LPWM, 0);
    analogWrite(RPWM, vel);
  }
  else
  {
    // gira para esquerda - rotate to the left
    analogWrite(RPWM, 0);
    analogWrite(LPWM, vel);
  }
}

void stopMotor() /*  function to stop the motor rotation  */
{
  // para o motor - stop the motor
  analogWrite(LPWM, 0);
  analogWrite(RPWM, 0);
}

// --------------------------------------------------------------------------------------------
// funções void setup e void loop

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  IrReceiv.enableIRIn();
}

void loop()
{

  static int pos = 0;
  int newPos;
  float ac = 0;

  if (IrReceiv.decode(&result))
  {
    Serial.print(result.bits);
    Serial.print(": ");
    Serial.println(result.value, HEX);

    switch (result.value)
    {

    case code1: // check

      //  parado
      for (unsigned long start = millis(); millis() - start <= 20000;)
      {
        stopMotor();
        Serial.print("Motor status:");
        Serial.print(" Stopped ");
        Serial.print("|| RPM: 0");
        Serial.println(" || PWM: 0");
      }

      ac = 0;
      // aceleração - check
      for (unsigned long start = millis(); millis() - start <= 10000;) // aceleração por 10 segundos
      {
        rotateMotor(true, map(ac, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Stopped -> Slow ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print("|| PWM: ");
          Serial.print(map(ac, 0, 100, 0, 255));
          Serial.print(" || ac: ");
          Serial.println(ac);
          pos = newPos;
        }
        ac = ac + 0.00047;
      }

      break;

    case code2: // check

      // velocidade lenta
      for (unsigned long start = millis(); millis() - start <= 110000;)
      {
        rotateMotor(true, map(40, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Moving ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print(" || PWM: ");
          Serial.println(map(40, 0, 100, 0, 255));
          pos = newPos;
        }
      }

      ac = 40;                                                         // aceleração - check
      for (unsigned long start = millis(); millis() - start <= 10000;) // aceleração por 10 segundos
      {
        rotateMotor(true, map(ac, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Slow -> Medium ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print("|| PWM: ");
          Serial.print(map(ac, 0, 100, 0, 255));
          Serial.print(" || ac: ");
          Serial.println(ac);
          pos = newPos;
        }
        ac = ac + 0.0008;
      }

      break;

    case code3: // check

      // velocidade média
      for (unsigned long start = millis(); millis() - start <= 110000;)
      {
        rotateMotor(true, map(70, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Moving ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print(" || PWM: ");
          Serial.println(map(70, 0, 100, 0, 255));
          pos = newPos;
        }
      }

      ac = 70;                                                         // aceleração - check
      for (unsigned long start = millis(); millis() - start <= 10000;) // aceleração por 10 segundos
      {
        rotateMotor(true, map(ac, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Medium -> Fast ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print("|| PWM: ");
          Serial.print(map(ac, 0, 100, 0, 255));
          Serial.print(" || ac: ");
          Serial.println(ac);
          pos = newPos;
        }
        ac = ac + 0.00135;
      }

      break;

    case code4: // check

      // velocidade rápida
      for (unsigned long start = millis(); millis() - start <= 110000;)
      {
        rotateMotor(true, map(100, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Moving ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print(" || PWM: ");
          Serial.println(map(100, 0, 100, 0, 255));
          pos = newPos;
        }
      }

      ac = 100;                                                        // desaceleração - check
      for (unsigned long start = millis(); millis() - start <= 10000;) // desaceleração por 10 segundos
      {
        rotateMotor(true, map(ac, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Fast -> Medium ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print("|| PWM: ");
          Serial.print(map(ac, 0, 100, 0, 255));
          Serial.print(" || ac: ");
          Serial.println(ac);
          pos = newPos;
        }
        ac = ac - 0.00139;
      }

      break;

    case code5:

      // velocidade média
      for (unsigned long start = millis(); millis() - start <= 120000;)
      {
        rotateMotor(true, map(70, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Moving ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print(" || PWM: ");
          Serial.println(map(70, 0, 100, 0, 255));
          pos = newPos;
        }
      }

      ac = 70;                                                         // desaceleração - check
      for (unsigned long start = millis(); millis() - start <= 10000;) // desaceleração por 10 segundos
      {
        rotateMotor(true, map(ac, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Medium -> Slow ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print("|| PWM: ");
          Serial.print(map(ac, 0, 100, 0, 255));
          Serial.print(" || ac: ");
          Serial.println(ac);
          pos = newPos;
        }
        ac = ac - 0.0008;
      }

      // velocidade lenta
      for (unsigned long start = millis(); millis() - start <= 120000;)
      {
        rotateMotor(true, map(40, 0, 100, 0, 255));
        encoder.tick();
        newPos = encoder.getPosition();
        if (pos != newPos)
        {
          Serial.print("Motor status:");
          Serial.print(" Moving ");
          Serial.print("|| RPM: ");
          Serial.print((int)(encoder.getRPM()));
          Serial.print(" || PWM: ");
          Serial.println(map(40, 0, 100, 0, 255));
          pos = newPos;
        }
      }
      break;

    default:
      Serial.println("ERROR");
      break;
    }
    IrReceiv.resume();
  }
  delay(1000);
}