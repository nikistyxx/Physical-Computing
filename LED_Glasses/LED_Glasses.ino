
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
   
   blinkleft[] =
{B00000000,
B00000000,
B00000000,
B10000001,
B11000001,
B01111110,
B01010100,
B01010100},

right[] =

{B00111100,
B01111110,
B11111111,
B11110011,
B11110011,
B11111111,
B01111110,
B00111100},

left[] =

{B00111100,
B01111110,
B11111111,
B11001111,
B11001111,
B11111111,
B01111110,
B00111100},

   look[] =
 
 {B00111100,
B01111110,
B11111111,
B11100111,
B11100111,
B11111111,
B01111110,
B00111100};


void loop() {
  

  matrix.clear();
  matrix.drawBitmap(0, 0, blinkleft, 8, 8, LED_RED);
  matrix.writeDisplay();
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, left, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, look, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(1500);

  matrix.clear();
  matrix.drawBitmap(0, 0, right, 8, 8, LED_GREEN);
  matrix.writeDisplay();
  delay(500);
  
  

  matrix.setRotation(0);
}



