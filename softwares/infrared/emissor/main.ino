/* Code for IR TRansmitter, to be used on Arduino Nano */

#include <Arduino.h>
#include <IRremote.hpp> // Library for InfraRed Transmitter 

// IR sentences
IRsend IrSend;
const int IR = 9; // pin connected

// Codes for every sequence
int codeON = 0xAA1;
//int code1 = 0xAA2;
//int code2 = 0xAA3;
//int code3 = 0xAA4;
//int codeOFF = 0xAA5;

int nBits = 12;

void setup()
{
  Serial.begin(9600);
  IrSend.begin(IR);
}

void loop()
{
  IrSend.sendSony(codeON, nBits); // Signal transmission
  //IrSend.sendSony(code1, nBits);
  //IrSend.sendSony(code2, nBits);
  //IrSend.sendSony(codeOFF, nBits);
  delay(300); // Delay between transmission
}
