// #include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
// #include <RotaryEncoder.h>
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

// // bts7960 pins
// const int L_EN = 7;
// const int R_EN = 8;
// const int L_PWM = 6;
// const int R_PWM = 5;

// // potentiometer pin
// const int pot = A0;
// float vel = 0;

// RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);

// float tgtangle = 0;
// float angle = 0;

// static int pos = 0;

// float returnAngle()
// {
//   pos = encoder.getPosition();

//   angle = (float)pos/PPR * 360;

//   return angle;
// }

// void printData()
// {
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

// void moveTo(float now, float target, int id)
// {
//   vel = ( analogRead( ( pot )/ 4 ) );
  
//   switch(id)
//   {
//     case 1: 
      
//       delay(1000); // single second dealy

//       // maintain the motor stopped
//       analogWrite(LPWM, 0);
//       analogWrite(RPWM, 0);

//       break;

//     case 2:

//     // recomended rpm: 1.5rpm = 540°/60s = 90°/10s

//       for(unsigned long start = millis(); millis() - start <= 10000;)
//       {
//         // perform the 90° counter-clockwise movement
//         analogWrite(LPWM, vel);
//         analogWrite(RPWM, 0);
//         printData();
//       }

//       break;

//     case 3:

//       // if-else structure to determine the direction of the motor rotation
//       if( target > 0 )
//       {
//         if( now <= target )
//         {
//           analogWrite(LPWM, 0);
//           analogWrite(RPWM, vel);
//         }
//         else
//         {
//           analogWrite(RPWM, 0);
//           analogWrite(LPWM, 0);
//         }
//       }
//       else
//       {
//         if( now >= target )
//         {
//           analogWrite(LPWM, 0);
//           analogWrite(RPWM, vel);
//         }
//         else
//         {
//           analogWrite(RPWM, 0);
//           analogWrite(LPWM, 0);
//         }
//       }
      
//       break;
//   }
// }



// void firstSeq()
// {
//   moveTo(90, 0, 1);
// }

// void secondSeq()
// {
//   moveTo(0, 180, 2);
// }

// void thirdSeq()
// {
//   moveTo((int)(encoder.getPosition()), 180, 3);
// }

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
  
//   firstSeq();
//   secondSeq();
//   thirdSeq();

// }