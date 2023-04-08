/* Example of how to use a IR receiver */

#include <Arduino.h>
#include <IRremote.hpp> // Library for the InfraRed receiver

// IR receiver parameters 
const int IR = 9; // pin connected
IRrecv IrReceiv(IR);
decode_results result;

const int codeON = 0xAA1;
const int code1 = 0xAA2;
const int code2 = 0xAA3;
const int codeOFF = 0xAA4;

void setup()
{
  Serial.begin(9600);
  IrReceiv.enableIRIn();
}

void loop()
{
  if (IrReceiv.decode(&result)) // If a signal is detected
  {
    Serial.print(result.bits);
    Serial.print(": ");
    Serial.println(result.value, HEX); // Prints the code received

    switch (result.value)
    {
      case codeON:

        break;
      case code1:

        break;
      case code2:

        break;
      case codeOFF:

        break;

      default:
        Serial.println("ERROR");
        break;
    }
    IrReceiv.resume(); // Clean the receiver for new signals
  }
  delay(1000);
}
