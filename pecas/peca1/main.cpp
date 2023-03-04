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

// botões - buttons
int b1 = 2;
int b2 = 3;

// variável da velocidade - velocity variables
float vel = 0;

// sentido de rotação - sense of rotation 
int state = 0;

// pino central do potenciometro - potentiometer center pin
int pot = A0;

// função que verifica o sentido de rotação - function that checks the sense of rotation
void changeState()
{

    if (digitalRead(b1) == LOW)
    {
        state = 0;
    }

    if (digitalRead(b2) == LOW)
    {
        state = 1;
    }

}

// função para girar o motor na velocidade e sentidos desejados - function to rotate the motor at the desired speed and directions
void rotateMotor()
{
    // leitura da velocidade pelo potenciometro - velocity reading by the potentiometer
    vel = ((analogRead(pot))/4);

    if (state == 0)
    {
        // gira para direita - rotate to the right
        analogWrite(LPWM, 0);
        analogWrite(RPWM, vel);
    }

    if (state == 1)
    {
        // gira para esquerda - rotate to the left
        analogWrite(RPWM, 0);
        analogWrite(LPWM, vel);
    }

}

void setup()
{

    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
    pinMode(b1, INPUT_PULLUP);
    pinMode(b2, INPUT_PULLUP);

}

void loop()
{

    changeState();
    rotateMotor();

}
