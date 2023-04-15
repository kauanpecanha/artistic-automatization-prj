#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <IRremote.hpp> // library for the IR receiver

// RPWM and LPWM pins setting
#define RPWM 5
#define LPWM 6

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

// velocity variable
float vel = 0;

// potentiometer center pin
int pot = A0;

int sequencia = 0;

// variable to get the beggining millisecond of a movement
long currentMillis;


// important information about the fourth sculpture
/*
  Pins connected to aduino( in english )

  IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
  IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
  IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
  IBT-2 pin 8 (GND) to Arduino's GND
  IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/


void rotateMotor(bool b) /*  function to set the rotation sense of the motor */
{
    // velocity reading by the potentiometer
    vel = ((analogRead(pot)) / 4);

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
  // fourth sculpture settings
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  IrReceiv.enableIRIn();
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
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
  switch (result.value)
    {
      
      case codeON:

        delay(1000); // a second delay

        currentMillis = millis(); // getting the beggining millissecond of this sequence
        while (millis() - currentMillis <= 10000)  // left rotation for 10 seconds
        {
            
            rotateMotor(false); // left rotation command

        }
        
        stopMotor(); // function to stop motor movement

        delay(10000); // 10 seconds delay

        currentMillis = millis(); // getting the beggining millissecond of this sequence
        while (millis() - currentMillis <= 40000) // left rotation for 40 seconds
        {
            
            rotateMotor(false); // left rotation command

        }

        stopMotor(); // function to stop motor movement
        
        break;

      case code1:
        
        delay(1000); // a second delay

        currentMillis = millis(); // getting the beggining millissecond of this sequence

        while (millis() - currentMillis <= 10000) // right rotation for 10 seconds
        {
            
            rotateMotor(true); // right rotation command

        }
        
        stopMotor(); // function to stop motor movement

        delay(5000); // five seconds delay

        // same variables and functions ideas are repeated on the code bellow

        currentMillis = millis();
        while (millis() - currentMillis <= 45000)
        {
            rotateMotor(true);
        }
        stopMotor();

        break;

      case code2:
        
        delay(1000);

        currentMillis = millis();
        while (millis() - currentMillis <= 10000)
        {
            rotateMotor(true);
        }
        currentMillis = millis();
        stopMotor();
        delay(200);
        while (millis() - currentMillis <= 20000)
        {
            rotateMotor(false);
        }
        currentMillis = millis();
        stopMotor();
        delay(200);
        while (millis() - currentMillis <= 30000)
        {
            rotateMotor(false);
        }
        stopMotor();

        break;

      case codeOFF:
        
        delay(1000);

        currentMillis = millis();
        while (millis() - currentMillis <= 20000)
        {
            rotateMotor(true);
        }
        stopMotor();
        delay(10000);

        currentMillis = millis();
        while (millis() - currentMillis <= 20000)
        {
            rotateMotor(false);
        }
        stopMotor();
        delay(5000);
        rotateMotor(true);
        break;


      default:

        Serial.println("ERROR");
        stopMotor();
        
        break;
    }
  delay(1000); // a second delay

}
