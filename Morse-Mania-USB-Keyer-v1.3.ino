/*
Morse Keyer EMULATION for the MORSE MANIA APP (Android / iOS)
via ARDUINO and real STRAIGHT KEY and/or PADDLE Input
===============================================================================================================================
(Free MORSE MANIA APP support on default only STRAIGHT-Key
For use with PADDLE (IAMBIC A/B etc.) you have to make an ONE-TIME-IN-APP Purchase)

Perfect for ARDUINO MICRO or LEONARDO with native USB-HID support
via the ATmega32U4 Controller and connected via USB-OTG Adapter on Android Tablet or Smartphone
(For iOS: Tested only with original Apple / Belkin "LIGHTNING to USB Adapter" with external power supply connected)
===============================================================================================================================
Version 1.3 by DL4KC
04.02.2023
*/

#include "Keyboard.h"

// Set pin numbers for the two inputs:
// Connect wire for Paddle DIT Key to DIGITAL INPUT 2 and 5V
// Connect wire for Paddle DAH Key to DIGITAL INPUT 3 and 5V
// Connect wire for STRAIGHT KEY to DIGITAL INPUT 4 and 5V
const int ditKey = 2;
const int dahKey = 3;
const int straightKey = 4;

// initialize the buttons' inputs and start Keyboard HID-MODE
void setup() {  
  pinMode(ditKey, INPUT);
  pinMode(dahKey, INPUT);
  pinMode(straightKey, INPUT);
  Keyboard.begin();
}

void loop() {

// if using Paddle and pressing DIT OR DAH it hold the buttons "A" and/or "S" on Virtual Keyboard, or press "SPACE" for STRAIGHT KEY
  while (digitalRead(ditKey) || digitalRead(dahKey) || digitalRead(straightKey)) {
    
    //DIT KEY
    if (digitalRead(ditKey) == HIGH) {
      Keyboard.press('[');
    } else Keyboard.release('[');
    
    //DAH KEY
    if (digitalRead(dahKey) == HIGH) {
      Keyboard.press(']');
    } else Keyboard.release(']');
    
    //STRAIGHT KEY
    if (digitalRead(straightKey) == HIGH) {
      Keyboard.press(' ');
    } else Keyboard.release(' ');

  }

//Give some time before returning the main loop and release all buttons
Keyboard.releaseAll();
delay(10);

}