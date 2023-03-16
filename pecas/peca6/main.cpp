// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: Header includes and defines inherited from receiver code */
//                                   /* Português-BR: Includes e Defines do cabeçalho, herdados do código do receptor */

// #include <Arduino.h> /* Just in case of using PlatformIO vscode extension for arduino programming */
// #include <IRremote.hpp>

// #include<RotaryEncoder.h>
// #define PPR 29
// #define RPWM 5
// #define LPWM 6

// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: Important info about the arduino connections, inherited from peca6 code */
//                                   /* Portguês-BR: Informações importantes sobre as conexões no arduino, herdadas do código peca6 */

// /*
//   Pins connected to aduino( in english )

//   IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
//   IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
//   IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V
//   IBT-2 pin 8 (GND) to Arduino's GND
//   IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
// */

// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: Settings of important data related to peca6 functions, inherited from peca6 code */
//                                   /* Portguês-BR: Configurações de dados importantes relacionados às funções da peça 6, herdadas do código peca6 */

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

// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: Settings of the used functions in this process, inherited from peca6 code */
//                                   /* Portguês-BR: Configurações das funções usadas neste processo, herdadas do código peca6 */

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
      
//       delay(1000); // single second delay

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

// void secondSeq()o
// {
//   moveTo(0, 180, 2);
// }

// void thirdSeq()
// {
//   moveTo(pos, 180, 3);
// }

// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: Settings of important data related to the receiver functions, inherited from receiver code */
//                                   /* Português-BR: Configuração de dados importantes relacionados às funções do receptor, herdadas do código do receptor */

// const int IR = 9;
// IRrecv IrReceiv(IR);
// decode_results result;

// const int code1 = 0xAA1;
// const int code2 = 0xAA2;
// const int code3 = 0xAA3;
// const int code4 = 0xAA4;

// // ----------------------------------------------------------------------------------------------------------------------------------------

//                                   /* English: void setup and void loop functions */
//                                   /* Português-BR: funções void setup e void loop */


// void setup()
// {
//   Serial.begin(9600);
//   pinMode(6, OUTPUT);
//   pinMode(5, OUTPUT);
//   IrReceiv.enableIRIn();
// }

// void loop()
// {
//   if (IrReceiv.decode(&result))
//   {
//     Serial.print(result.bits);
//     Serial.print(": ");
//     Serial.println(result.value, HEX);

//     switch (result.value)
//     {
//       case code1:
//         firstSeq();
//         break;
//       case code2:
//         secondSeq();
//         break;
//       case code3:
//         thirdSec();
//         break;
      
//       default:
//         Serial.println("ERROR");
//         break;
//     }
//     IrReceiv.resume();
//   }
//   delay(1000);
// }