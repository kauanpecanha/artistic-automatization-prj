#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#define RPWM 5
#define LPWM 6

/*
  Pins connected to aduino( in english )

  IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
  IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
  IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
  IBT-2 pin 8 (GND) to Arduino's GND
  IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/

// variável da velocidade - velocity variables
float vel = 0;

// pino central do potenciometro - potentiometer center pin
int pot = A0;

int sequencia = 0;

long currentMillis;

void rotateMotor(bool b) /*  function to set the sense of rotation of the motor */
{
    // leitura da velocidade pelo potenciometro - velocity reading by the potentiometer
    vel = ((analogRead(pot)) / 4);

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

void setup()
{

    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
}

void loop()
{
    sequencia = random(1, 5);
    switch (sequencia)
    {
    case 1: /*Seq 1*/
        delay(1000);

        currentMillis = millis();
        while (millis() - currentMillis <= 10000)
        {
            rotateMotor(false);
        }
        stopMotor();
        delay(10000);

        currentMillis = millis();
        while (millis() - currentMillis <= 40000)
        {
            rotateMotor(false);
        }
        stopMotor();
        break;

    case 2: /*Seq 2*/
        delay(1000);

        currentMillis = millis();
        while (millis() - currentMillis <= 10000)
        {
            rotateMotor(true);
        }
        stopMotor();
        delay(5000);

        currentMillis = millis();
        while (millis() - currentMillis <= 45000)
        {
            rotateMotor(true);
        }
        stopMotor();
        break;

    case 3: /*Seq 3*/
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

    case 4: /*Seq 4*/
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
        stopMotor();
        break;
    }
}
