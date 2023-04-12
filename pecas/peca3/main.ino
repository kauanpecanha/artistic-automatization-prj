#include <Arduino.h> /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <RotaryEncoder.h> // library for encoder using
#include <IRremote.hpp> // library for the IR receiver

/* 
  CODE FOR 1/4 STEPS, 800 STEPS PER REVOLUTION, 1 * RELATION
*/

// IR receiver parameters 
const int IR = 9; // pin connected
IRrecv IrReceiv(IR);
decode_results result;

// IR codes
const int codeON = 0xAA1;
const int codeOFF = 0xAA4;

// Arm & Forearm 1 EN - DIR - PUL(STP)
#define ARM1_EN 22
#define ARM1_DIR 23
#define ARM1_STP 24
#define FOREARM1_EN 25
#define FOREARM1_DIR 26
#define FOREARM1_STP 27

// Arm & Forearm 2 EN - DIR - PUL(STP)
#define ARM2_EN 28
#define ARM2_DIR 29
#define ARM2_STP 30
#define FOREARM2_EN 31
#define FOREARM2_DIR 32
#define FOREARM2_STP 33

// Arm & Forearm 3 EN - DIR - PUL(STP)
#define ARM3_EN 34
#define ARM3_DIR 35
#define ARM3_STP 36
#define FOREARM3_EN 37
#define FOREARM3_DIR 38
#define FOREARM3_STP 39

// Arm & Forearm 4 EN - DIR - PUL(STP)
#define ARM4_EN 40
#define ARM4_DIR 41
#define ARM4_STP 42
#define FOREARM4_EN 43
#define FOREARM4_DIR 44
#define FOREARM4_STP 45

// Delay between steps == velocity
const int delayTime = 200;

// Resolution relation
const float RELATION_ARM = 19.1;
const float RELATION_FOREARM = 11.35;

// Rotary encoder pins
#define DT_A1 2
#define CLK_A1 3
#define DT_FA1 4
#define CLK_FA1 5
RotaryEncoder encoder_A1(DT_A1, CLK_A1, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA1(DT_FA1, CLK_FA1, RotaryEncoder::LatchMode::TWO03);

#define DT_A2 6
#define CLK_A2 7
#define DT_FA2 8
#define CLK_FA2 9
RotaryEncoder encoder_A2(DT_A2, CLK_A2, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA2(DT_FA2, CLK_FA2, RotaryEncoder::LatchMode::TWO03);

#define DT_A3 10
#define CLK_A3 11
#define DT_FA3 12
#define CLK_FA3 13
RotaryEncoder encoder_A3(DT_A3, CLK_A3, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA3(DT_FA3, CLK_FA3, RotaryEncoder::LatchMode::TWO03);

#define DT_A4 14
#define CLK_A4 15
#define DT_FA4 16
#define CLK_FA4 17
RotaryEncoder encoder_A4(DT_A4, CLK_A4, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder_FA4(DT_A4, CLK_FA4, RotaryEncoder::LatchMode::TWO03);

void getPosition_A1()
{

  static int pos = 0;
  encoder_A1.tick();
  int newPos = encoder_A1.getPosition();
  
  if (pos != newPos)
  {

    pos = newPos;

  }

  Serial.print(" | ARM1 position = ");
  Serial.print(pos);
  Serial.print(" |");

}
void getPosition_FA1()
{
  
  static int pos = 0;
  encoder_FA1.tick();
  int newPos = encoder_FA1.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | FOREARM1 position = ");
  Serial.print(pos);
  Serial.print(" |");

}

void getPosition_A2()
{
  
  static int pos = 0;
  encoder_A2.tick();
  int newPos = encoder_A2.getPosition();
  if (pos != newPos)
  {
    pos = newPos;
  }
  Serial.print(" | ARM2 position = ");
  Serial.print(pos);
  Serial.print(" |");

}
void getPosition_FA2()
{
  
  static int pos = 0;
  encoder_FA2.tick();
  int newPos = encoder_FA2.getPosition();
  
  if (pos != newPos)
  {
    
    pos = newPos;

  }
  
  Serial.print(" | FOREARM2 position = ");
  Serial.print(pos);
  Serial.print(" |");

}

void getPosition_A3()
{
  
  static int pos = 0;
  encoder_A3.tick();
  int newPos = encoder_A3.getPosition();
  
  if (pos != newPos)
  {
  
    pos = newPos;

  }
  
  Serial.print(" | ARM3 position = ");
  Serial.print(pos);
  Serial.print(" |");
}
void getPosition_FA3()
{
  
  static int pos = 0;
  encoder_FA3.tick();
  int newPos = encoder_FA3.getPosition();
  
  if (pos != newPos)
  {
    
    pos = newPos;

  }
  
  Serial.print(" | FOREARM3 position = ");
  Serial.print(pos);
  Serial.print(" |");

}

void getPosition_A4()
{
  
  static int pos = 0;
  encoder_A4.tick();
  int newPos = encoder_A4.getPosition();
  
  if (pos != newPos)
  {
    
    pos = newPos;

  }
  
  Serial.print(" | ARM4 position = ");
  Serial.print(pos);
  Serial.print(" |");

}
void getPosition_FA4()
{
  
  static int pos = 0;
  encoder_FA4.tick();
  int newPos = encoder_FA4.getPosition();
  
  if (pos != newPos)
  {
    
    pos = newPos;

  }

  Serial.print(" | FOREARM4 position = ");
  Serial.print(pos);
  Serial.print(" |");

}

void setup()
{
  // set pins as output
  pinMode(ARM1_DIR, OUTPUT);
  pinMode(ARM1_STP, OUTPUT);
  pinMode(ARM2_DIR, OUTPUT);
  pinMode(ARM2_STP, OUTPUT);
  pinMode(ARM3_DIR, OUTPUT);
  pinMode(ARM3_STP, OUTPUT);
  pinMode(ARM4_DIR, OUTPUT);
  pinMode(ARM4_STP, OUTPUT);
  
  pinMode(FOREARM1_STP, OUTPUT);
  pinMode(FOREARM1_DIR, OUTPUT);
  pinMode(FOREARM2_STP, OUTPUT);
  pinMode(FOREARM2_DIR, OUTPUT);
  pinMode(FOREARM3_STP, OUTPUT);
  pinMode(FOREARM3_DIR, OUTPUT);
  pinMode(FOREARM4_STP, OUTPUT);
  pinMode(FOREARM4_DIR, OUTPUT);
  
  pinMode(ARM1_EN, OUTPUT);
  pinMode(ARM2_EN, OUTPUT);
  pinMode(ARM3_EN, OUTPUT);
  pinMode(ARM4_EN, OUTPUT);
  
  pinMode(FOREARM1_EN, OUTPUT);
  pinMode(FOREARM2_EN, OUTPUT);
  pinMode(FOREARM3_EN, OUTPUT);
  pinMode(FOREARM4_EN, OUTPUT);
  
  // enable the motor driver
  digitalWrite(ARM1_EN, LOW);
  digitalWrite(ARM2_EN, LOW);
  digitalWrite(ARM3_EN, LOW);
  digitalWrite(ARM4_EN, LOW);
  digitalWrite(FOREARM1_EN, LOW);
  digitalWrite(FOREARM2_EN, LOW);
  digitalWrite(FOREARM3_EN, LOW);
  digitalWrite(FOREARM4_EN, LOW);

  Serial.begin(9600); // or higher baud rate
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
  // commands to get data from both arm and forearm, uncomment to separated adjustment of arm and forearm
  getPosition_A1();
  getPosition_FA1();
  Serial.println();
//   getPosition_A2();
//   getPosition_FA2();
//   Serial.println();
//   getPosition_A3();
//   getPosition_FA3();
//   Serial.println();
//   getPosition_A4();
//   getPosition_FA4();
//   Serial.println();

  digitalWrite(ARM1_DIR, 1);
  digitalWrite(ARM2_DIR, 1);
  digitalWrite(ARM3_DIR, 1);
  digitalWrite(ARM4_DIR, 1);
  
  // ARM: turn 800 steps (360°) into direction 1
  for (int i = 0; i < 800 * RELATION_ARM; i++) // multiply the steps for the correct resolution 
  {
    
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
//     getPosition_A2();
//     getPosition_FA2();
//     Serial.println();
//     getPosition_A3();
//     getPosition_FA3();
//     Serial.println();
//     getPosition_A4();
//     getPosition_FA4();
//     Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);

  }

  delay(100);

  digitalWrite(FOREARM1_DIR, 1);
  digitalWrite(FOREARM2_DIR, 1);
  digitalWrite(FOREARM3_STP, 1);
  digitalWrite(FOREARM4_STP, 1);

  // FOREARM: turn 900 steps (360°+45°) into direction 1
  for (int i = 0; i < 900 * RELATION_FOREARM; i++)
  {
    
    digitalWrite(FOREARM1_STP, HIGH);
    digitalWrite(FOREARM2_STP, HIGH);
    digitalWrite(FOREARM3_STP, HIGH);
    digitalWrite(FOREARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
//     getPosition_A2();
//     getPosition_FA2();
//     Serial.println();
//     getPosition_A3();
//     getPosition_FA3();
//     Serial.println();
//     getPosition_A4();
//     getPosition_FA4();
//     Serial.println();
    digitalWrite(FOREARM1_STP, LOW);
    digitalWrite(FOREARM2_STP, LOW);
    digitalWrite(FOREARM3_STP, LOW);
    digitalWrite(FOREARM4_STP, LOW);
    delayMicroseconds(delayTime);

  }
  
  delay(250);

  digitalWrite(FOREARM1_DIR, 0);
  digitalWrite(FOREARM2_DIR, 0);
  digitalWrite(FOREARM3_STP, 0);
  digitalWrite(FOREARM4_STP, 0);
  
  // FOREARM: turn 100 steps (-45°) into direction 0
  for (int i = 0; i < 100 * RELATION_FOREARM; i++)
  {
    
    digitalWrite(FOREARM1_STP, HIGH);
    digitalWrite(FOREARM2_STP, HIGH);
    digitalWrite(FOREARM3_STP, HIGH);
    digitalWrite(FOREARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
//     getPosition_A2();
//     getPosition_FA2();
//     Serial.println();
//     getPosition_A3();
//     getPosition_FA3();
//     Serial.println();
//     getPosition_A4();
//     getPosition_FA4();
//     Serial.println();
    digitalWrite(FOREARM1_STP, LOW);
    digitalWrite(FOREARM2_STP, LOW);
    digitalWrite(FOREARM3_STP, LOW);
    digitalWrite(FOREARM4_STP, LOW);
    delayMicroseconds(delayTime);

  }
  
  delay(100);

  digitalWrite(ARM1_DIR, 0);
  digitalWrite(ARM2_DIR, 0);
  digitalWrite(ARM3_STP, 0);
  digitalWrite(ARM4_STP, 0);

  // ARM: turn 100 steps (-45°) into direction 0
  for (int i = 0; i < 100 * RELATION_ARM; i++)
  {
    
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
//     getPosition_A2();
//     getPosition_FA2();
//     Serial.println();
//     getPosition_A3();
//     getPosition_FA3();
//     Serial.println();
//     getPosition_A4();
//     getPosition_FA4();
//     Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);

  }
  
  delay(1000);

  digitalWrite(ARM1_DIR, 1);
  digitalWrite(ARM2_DIR, 1);
  digitalWrite(ARM3_STP, 1);
  digitalWrite(ARM4_STP, 1);
  
  // FOREARM: turn 100 steps (45°) into direction 1
  for (int i = 0; i < 100 * RELATION_ARM; i++)
  {
    
    digitalWrite(ARM1_STP, HIGH);
    digitalWrite(ARM2_STP, HIGH);
    digitalWrite(ARM3_STP, HIGH);
    digitalWrite(ARM4_STP, HIGH);
    delayMicroseconds(delayTime);
    getPosition_A1();
    getPosition_FA1();
    Serial.println();
//     getPosition_A2();
//     getPosition_FA2();
//     Serial.println();
//     getPosition_A3();
//     getPosition_FA3();
//     Serial.println();
//     getPosition_A4();
//     getPosition_FA4();
//     Serial.println();
    digitalWrite(ARM1_STP, LOW);
    digitalWrite(ARM2_STP, LOW);
    digitalWrite(ARM3_STP, LOW);
    digitalWrite(ARM4_STP, LOW);
    delayMicroseconds(delayTime);

  }
        break;
        case codeOFF:
        
        break;
        default:
        Serial.println("ERROR");
        break;
    }
    IrReceiv.resume(); // Clean the receiver for new signals
  }
}
