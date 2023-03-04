// #include <Arduino.h>
// #include <RotaryEncoder.h>
// #include <BTS7960.h>
// #define PPR 33.5

// int seq = 1;

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

// RotaryEncoder encoder(pin1, pin2, RotaryEncoder::LatchMode::TWO03);
// BTS7960 motor(L_EN, R_EN, L_PWM, R_PWM);

// float tgtangle = 2000;
// float angle = 0;

// void moveTo(float now, float target) {
//   if (now <= target) {
//     if (target > 0) {
//       motor.TurnRight(255);
//     } else {
//       motor.TurnLeft(255);
//     }
//   } else {
//     motor.Stop();
//     encoder.setPosition(0);
//     seq++;
//   }
// }

// void getAngle() {
//   static int pos = 0;
//   encoder.tick();

//   int newPos = encoder.getPosition();
//   if (pos != newPos) {
//     Serial.print("Pos:");
//     Serial.println(newPos);
//     angle = (float)newPos / PPR * 360;
//     Serial.print("Desired angle: ");
//     Serial.print(tgtangle);
//     Serial.print(" || Actual angle: ");
//     Serial.println(angle);
//     Serial.print(" dir:");
//     Serial.println((int)(encoder.getDirection()));
//     pos = newPos;
//   }
// }

// void setup() {
//   Serial.begin(9600);
//   motor.Enable();
// }

// void loop() {
//   getAngle();

//   switch (seq) {
//     case 1:
//     moveTo(angle,2400);
//       break;
//     case 2:
//     moveTo(angle,3000);
//       break;
//     case 3:
//     moveTo(angle,);
//       break;
//     case 4:
//     moveTo(angle,);
//       break;
//     case 5:
//     moveTo(angle,);
//       break;
//     default:
//       seq = 1;    
//   }
// }