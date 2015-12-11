/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  Atmel SAMD21/W25 Xplained pros have a buitin LED connected to D13: LED0
  updated 15 Dec 2015 by T. VIARD
 */

// the setup function runs once when you press reset or power the board
void setup(void)
{
  // initialize digital pin 13 as an output.
  pinMode(PIN_LED_13, OUTPUT);
}

// the loop function runs over and over again forever
void loop(void)
{
  digitalWrite(PIN_LED_13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(PIN_LED_13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
