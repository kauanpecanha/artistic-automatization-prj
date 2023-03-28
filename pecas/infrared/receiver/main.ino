// #include <Arduino.h>
// #include <IRremote.hpp>

// const int IR = 9;
// IRrecv IrReceiv(IR);
// decode_results result;

// const int code1 = 0xAA1;
// const int code2 = 0xAA2;
// const int code3 = 0xAA3;
// const int code4 = 0xAA4;

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
//         analogWrite(5, 255);
//         analogWrite(6, 0);
//         break;
//       case code2:
//         analogWrite(5, 0);
//         analogWrite(6, 255);
//         break;
//       case code3:
//         analogWrite(5, 0);
//         analogWrite(6, 0);
//         break;
//       case code4:
//         analogWrite(5, 104);
//         analogWrite(6, 0);
//         break;

//       default:
//         Serial.println("ERROR");
//         break;
//     }
//     IrReceiv.resume();
//   }
//   delay(1000);
// }