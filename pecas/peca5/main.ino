#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <IRremote.hpp> // Library for the IR receiver
#include <RotaryEncoder.h> // Library for encoder using

// ibt2's RPWM and LPWM pins
#define RPWM 5
#define LPWM 6


// important information about the fifth sculpture setting
/*
  Pins connected to aduino( in english )

  IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
  IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
  IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
  IBT-2 pin 8 (GND) to Arduino's GND
  IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/

/*
  IMPORTANT WARNING
  
  In case of changing the speed of the movements, the acceleration must be changed the same way, manually, according to what's desired, just like the decimal numbers increased or decreased to the ac variable at the final of acceleration or deceleration iterations. 
  It must be done within attempts of values, always checking the serial monitor to check if the decimal number is enough to what is desired, in order to look for smooth transitions beetween the sequences. 
*/

// IR receive parameters
const int IR = 9;
IRrecv IrReceiv(IR);
decode_results result;

// IR codes
const int codeON = 0xAA1;
const int code1 = 0xAA2;
const int code2 = 0xAA3;
const int code3 = 0xAA4;
const int codeOFF = 0xAA5;


// rotary encoder pins
const int pin1 = 2;
const int pin2 = 3;

RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);


void rotateMotor(bool b, int vel) /*  function to set the rotation sense of the motor */
{
  if (b == true)
  {
    // rotate to the right
    analogWrite(LPWM, 0);
    analogWrite(RPWM, vel);
  }
  else
  {
    // rotate to the left
    analogWrite(RPWM, 0);
    analogWrite(LPWM, vel);
  }
}

void stopMotor() /*  function to stop the motor rotation  */
{
  // stop the motor
  analogWrite(LPWM, 0);
  analogWrite(RPWM, 0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  IrReceiv.enableIRIn();
}

void loop()
{

  static int pos = 0; // variable to store the beggining location of the movement
  int newPos; // variable to store the position at that momento of the movement
  float ac = 0; // variable for acceleration control

  if (IrReceiv.decode(&result))
  {
    Serial.print(result.bits);
    Serial.print(": ");
    Serial.println(result.value, HEX);

    switch (result.value)
    {

    case codeON: 

      //  stopped
      for (unsigned long start = millis(); millis() - start <= 20000;)
      {
        stopMotor();
        Serial.print("Motor status:");
        Serial.print(" Stopped ");
        Serial.print("|| RPM: 0");
        Serial.println(" || PWM: 0");
      }

      ac = 0;
      // acceleration
      for (unsigned long start = millis(); millis() - start <= 10000;) // 10 seconds long acceleration
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
        ac = ac + 0.00047; // acceleration increasing
      }

      break;

    case code1: 

      // slow speed
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

      ac = 40;                                                         
      // acceleration
      for (unsigned long start = millis(); millis() - start <= 10000;) // 10 seconds long acceleration
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
        ac = ac + 0.0008; // acceleration increasing
      }

      break;

    case code2:

      // medium speed
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

      ac = 70;
      // acceleration
      for (unsigned long start = millis(); millis() - start <= 10000;) // 10 seconds long acceleration
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
        ac = ac + 0.00135; // acceleration increasing
      }

      break;

    case code3:

      // fast speed
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

      ac = 100;
      // deceleration
      for (unsigned long start = millis(); millis() - start <= 10000;) // 10 seconds long deceleration
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
        ac = ac - 0.00139; // acceleration decreasing
      }

      break;

    case codeOFF:

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

      ac = 70;
      // deceleration
      for (unsigned long start = millis(); millis() - start <= 10000;) // 10 seconds long deceleration
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
        ac = ac - 0.0008; // acceleration decreasing
      }

      // slow speed
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