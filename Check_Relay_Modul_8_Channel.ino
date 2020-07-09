/*
  Relay Blink

  Turns an Relay on for one second,
  then off for one second, repeatedly.

  https://github.com/YuriiSalimov/RelayModule

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/

#include <RelayModule.h>
RelayModule* relay = NULL;
// the setup function runs once when you press reset or power the board
void setup() {

}
// the loop function runs over and over again forever
void loop() {
  for (int i = 2; i < 10; i++)
  {
    relay = new RelayModule(i);
    relay->on();
    delay(100);
  }

  delay(1000);
  for (int i = 9; i > 1; i--)
  {
    relay = new RelayModule(i);
    relay->off();
    delay(100);
  }
  delay(1000);
}
