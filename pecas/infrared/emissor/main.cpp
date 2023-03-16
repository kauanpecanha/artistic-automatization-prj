// #include <Arduino.h>
// #include <IRremote.hpp>

// IRsend IrSend;
// const int IR = 9;

// int code1 = 0xAA1;
// int code2 = 0xAA2;
// int code3 = 0xAA3;
// int code4 = 0xAA4;

// int nBits = 12;

// int seq;

// void setup()
// {
//   Serial.begin(9600);
//   IrSend.begin(IR);
// }

// void loop()
// {
//   if (Serial.available() > 0)
//   {
//     seq = Serial.parseInt();
//   }
//   Serial.print(seq);
//   switch (seq)
//   {
//   case 1:
//     IrSend.sendSony(code1, nBits);
//     break;
//   case 2:
//     IrSend.sendSony(code2, nBits);
//     break;
//   case 3:
//     IrSend.sendSony(code3, nBits);
//     break;
//   case 4:
//     IrSend.sendSony(code4, nBits);
//     break;
//   default:
//     break;
//   }
//   delay(300);
// }