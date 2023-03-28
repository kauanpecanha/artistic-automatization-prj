// #include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
// #include <RotaryEncoder.h>
// #include <IRremote.hpp>
// #define PPR 29
// #define RPWM 5
// #define LPWM 6

// /*
//   Pins connected to aduino( in english )

//   IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
//   IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
//   IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
//   IBT-2 pin 8 (GND) to Arduino's GND
//   IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
// */

// // rotary encoder pins
// const int pin1 = 2;
// const int pin2 = 3;
// RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);

// // potentiometer pin
// const int pot = A0;
// float vel = 0;

// float tgtangle = 30;
// float angle = 0;

// // IR receiver
// const int IR = 9;
// IRrecv IrReceiv(IR);
// decode_results result;

// // ON/OFF codes
// const int code1 = 0xAA1; // on
// const int code2 = 0xAA2; // off

// void moveTo(float now, float target)
// {
//   // vel = (analogRead(pot) / 4);
//   vel = 100;
//   if (target > 0)
//   {
//     if (now <= target)
//     {
//       analogWrite(LPWM, 0);
//       analogWrite(RPWM, vel);
//     }
//     else
//     {
//       analogWrite(RPWM, 0);
//       analogWrite(LPWM, 0);
//       delay(200);
//       tgtangle = -30;
//     }
//   }
//   else
//   {
//     if (now >= target)
//     {
//       analogWrite(RPWM, 0);
//       analogWrite(LPWM, vel);
//     }
//     else
//     {
//       analogWrite(RPWM, 0);
//       analogWrite(LPWM, 0);
//       delay(200);
//       tgtangle = 30;
//     }
//   }
// }

// void stopMottor()
// {
//   analogWrite(RPWM, 0);
//   analogWrite(LPWM, 0);
// }

// void getAngle()
// {
//   static int pos = 0;
//   encoder.tick();
//   int newPos = encoder.getPosition();
//   if (pos != newPos)
//   {
//     angle = (float)newPos / PPR * 360;
//     Serial.print("Desired angle: ");
//     Serial.print(tgtangle);
//     Serial.print(" || Actual angle: ");
//     Serial.print(angle);
//     Serial.print(" || Direction: ");
//     Serial.print((int)(encoder.getDirection()));
//     Serial.print(" || RPM: ");
//     Serial.println((int)(encoder.getRPM()));
//     pos = newPos;
//   }
// }

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
//   if (IrReceiv.decode(&result))
//   {
//     Serial.print(result.bits);
//     Serial.print(": ");
//     Serial.println(result.value, HEX);
//     IrReceiv.resume();
//   }
//   switch (result.value)
//   {
//   case code1:
//     getAngle();
//     Serial.println("Move");
//     moveTo(angle, tgtangle);
//     break;
//   case code2:
//     Serial.println("Stop");
//     stopMottor();
//     break;
//   default:
//     Serial.println("ERROR");
//     stopMottor();
//     break;
//   }
// }