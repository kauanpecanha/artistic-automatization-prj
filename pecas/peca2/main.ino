#include <Arduino.h>    /* Just in case of using the vscode ide for arduino programming, not needed if using the commom arduino ide */
#include <IRremote.hpp> // Library for the IR receiver
#include <Servo.h>      // Library for the servo motor

// parameters used on movement
#define FPS 24
#define FRAMES 250
#define PWM_PIN 3

// ibt2's RPWM and LPWM pins
#define RPWM 5
#define LPWM 6

// variable velocity
float vel = 0;

// potentiometer
int pot = A0;

// IR receive parameters
const int IR = 9;
IRrecv IrReceiv(IR);
decode_results result;

// IR codes
const int codeON = 0xAA1;
const int codeOFF = 0xAA5;

// angle of the movement
const float Bone[250] PROGMEM = {
    90.0,
    90.0,
    90.010,
    90.037,
    90.080,
    90.142,
    90.223,
    90.323,
    90.446,
    90.590,
    90.759,
    90.954,
    91.176,
    91.428,
    91.711,
    92.030,
    92.385,
    92.782,
    93.223,
    93.714,
    94.259,
    94.865,
    95.539,
    96.290,
    97.128,
    98.068,
    99.125,
    100.32,
    101.68,
    103.24,
    105.04,
    107.14,
    109.61,
    112.49,
    115.71,
    119.01,
    121.97,
    124.34,
    126.13,
    127.43,
    128.38,
    129.04,
    129.50,
    129.79,
    129.95,
    129.99,
    129.92,
    129.70,
    129.32,
    128.80,
    128.12,
    127.30,
    126.34,
    125.24,
    124.01,
    122.65,
    121.18,
    119.59,
    117.90,
    116.13,
    114.27,
    112.36,
    110.39,
    108.39,
    106.38,
    104.36,
    102.35,
    100.38,
    98.457,
    96.589,
    94.797,
    93.093,
    91.490,
    90.0,
    88.591,
    87.228,
    85.911,
    84.640,
    83.416,
    82.238,
    81.108,
    80.025,
    78.988,
    78.000,
    77.058,
    76.164,
    75.316,
    74.515,
    73.760,
    73.051,
    72.386,
    71.766,
    71.190,
    70.655,
    70.162,
    69.709,
    69.295,
    68.917,
    68.575,
    68.267,
    67.991,
    67.745,
    67.527,
    67.334,
    67.165,
    67.016,
    66.886,
    66.772,
    66.671,
    66.581,
    66.500,
    66.565,
    66.715,
    66.939,
    67.228,
    67.575,
    67.976,
    68.425,
    68.920,
    69.456,
    70.031,
    70.643,
    71.291,
    71.971,
    72.683,
    73.425,
    74.197,
    74.997,
    75.825,
    76.679,
    77.559,
    78.464,
    79.395,
    80.350,
    81.329,
    82.331,
    83.357,
    84.407,
    85.480,
    86.575,
    87.694,
    88.835,
    90.0,
    91.172,
    92.329,
    93.453,
    94.528,
    95.537,
    96.463,
    97.296,
    98.023,
    98.638,
    99.138,
    99.522,
    99.790,
    99.948,
    99.999,
    99.987,
    99.949,
    99.884,
    99.793,
    99.674,
    99.527,
    99.351,
    99.146,
    98.912,
    98.649,
    98.357,
    98.036,
    97.686,
    97.310,
    96.907,
    96.478,
    96.026,
    95.551,
    95.056,
    94.541,
    94.010,
    93.465,
    92.906,
    92.338,
    91.760,
    91.177,
    90.590,
    90.0,
    89.414,
    88.840,
    88.279,
    87.732,
    87.199,
    86.683,
    86.184,
    85.704,
    85.243,
    84.805,
    84.388,
    83.996,
    83.628,
    83.285,
    82.968,
    82.677,
    82.412,
    82.173,
    81.960,
    81.772,
    81.608,
    81.467,
    81.348,
    81.249,
    81.170,
    81.109,
    81.065,
    81.036,
    81.020,
    81.017,
    81.026,
    81.052,
    81.101,
    81.172,
    81.262,
    81.370,
    81.496,
    81.637,
    81.793,
    81.963,
    82.147,
    82.343,
    82.552,
    82.772,
    83.003,
    83.245,
    83.497,
    83.759,
    84.031,
    84.313,
    84.604,
    84.904,
    85.213,
    85.531,
    85.859,
    86.195,
    86.541,
    86.897,
    87.263,
    87.640,
    88.029,
    88.433,
    88.854,
    89.303,
    89.821,
}; /*  vector of positions inherited from blender  */

const float frameDurationMillis = 1000 / FPS;                       /* single frame duration  */
const float animationDurationMillis = FRAMES * frameDurationMillis; /* total duration of the animation */
long startMillis = millis();                                        /* initial frame  */

Servo myservo; /*  declaration of the object myservo of the type servo  */

void rotateMotor(bool b) /*  function to set the rotation sense of the motor */
{

    // velocity reading by the potentiometer
    vel = ((analogRead(pot)) / 4); // velocity set by the potentiometer

    if (b == true)
    {
        // rotate to the right
        analogWrite(LPWM, 0);
        analogWrite(RPWM, vel);
    }
    else
    {
        // rotate to the left
        analogWrite(RPWM, 0);
        analogWrite(LPWM, vel);
    }
    
}

void stopMotor() /*  function to stop the motor rotation  */
{

    // stop the motor
    analogWrite(LPWM, 0);
    analogWrite(RPWM, 0);
}

void setup()
{

    Serial.begin(9600);
    IrReceiv.enableIRIn();
    myservo.attach(PWM_PIN);
    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
    
}

void loop()
{

    if (IrReceiv.decode(&result))
    {

        Serial.print(result.bits);
        Serial.print(": ");
        Serial.println(result.value, HEX);
        IrReceiv.resume();
    }

    switch (result.value)
    {
        case codeON:
            
            long currentMillis = millis();                     /*   milisseconds of the current moment */
            long positionMillis = currentMillis - startMillis; /*   exact milissecond since the beggining of the programm */

            if (positionMillis >= animationDurationMillis)
            {
                
                startMillis = currentMillis;

            }
            else
            {
                
                long frame = floor(positionMillis / frameDurationMillis);
                float positionValue = pgm_read_float_near(Bone + frame);

                myservo.write(positionValue);

                if (positionMillis >= 25 && positionMillis <= 45)
                {
                    
                    rotateMotor(true);

                }

                else if (positionMillis >= 52 && positionMillis <= 71)
                {
                    
                    rotateMotor(false);

                }

                else if (positionMillis >= 90 && positionMillis <= 135)
                {
                    
                    rotateMotor(true);

                }

                else if (positionMillis >= 156 && positionMillis <= 181)
                {
                    
                    rotateMotor(false);

                }

                else if (positionMillis >= 182 && positionMillis <= 238)
                {
                    
                    rotateMotor(true);

                }
                else
                {
                    
                    stopMotor();

                }
            }
            
            break;

        case codeOFF:
            
            stopMotor();

        default:
            
            Serial.println("ERROR");
            stopMotor();
            break;

    }
}
