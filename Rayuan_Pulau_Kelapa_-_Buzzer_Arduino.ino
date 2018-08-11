/*
Judul Lagu: Rayuan Pulau Kelapa
Ciptaan: Ismail Marzuki
----------------------------------
Pin Buzzer nomor D9, Pin LED nomor D2
Pastikan beri resistor 330 Ohm sebelum LED
Modified by Belajar Robot Team
---------------------------------------
||  http://youtube.com/BelajarRobot  ||
---------------------------------------
*/

#include "Volume3.h"

int nada[] = {
  0, 523, 587, 659, 698,  783, 880, 987, 1046, 1174,
  1318, 1396, 1567, 1769, 1975, 2093
};

int buzzPin = 9;
int amp = 100;

void setup() {
  pinMode(2, OUTPUT);
}

void bunyi(int nadaKe, int lama)
{
  vol.tone(buzzPin, nada[nadaKe], amp);
  digitalWrite(2, HIGH);
  delay(lama * 0.9);
  digitalWrite(2, LOW);
  delay(lama * 0.1);
}

void loop() {
  rayuanPulauKelapa();
}

void rayuanPulauKelapa()
{
  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(3, 500);
  bunyi(4, 500);
  bunyi(5, 500);
  bunyi(6, 1000);
  bunyi(5, 1000);
  bunyi(0, 1000);

  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(7, 500);
  bunyi(6, 500);
  bunyi(7, 700);
  bunyi(5, 300);
  bunyi(4, 1000);
  bunyi(0, 1000);

  bunyi(4, 500);
  bunyi(4, 500);
  bunyi(4, 500);
  bunyi(4, 500);
  bunyi(2, 500);
  bunyi(3, 500);
  bunyi(4, 500);
  bunyi(5, 700);
  bunyi(4, 300);
  bunyi(4, 1000);
  bunyi(0, 1000);

  bunyi(7, 500);
  bunyi(7, 500);
  bunyi(7, 500);
  bunyi(7, 500);
  bunyi(8, 500);
  bunyi(7, 500);
  bunyi(6, 500);
  bunyi(5, 1500);
  bunyi(0, 1000);

  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(5, 500);
  bunyi(3, 500);
  bunyi(4, 500);
  bunyi(5, 500);
  bunyi(6, 700);
  bunyi(5, 300);
  bunyi(5, 1000);
  bunyi(0, 1000);

  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(8, 500);
  bunyi(7, 500);
  bunyi(8, 500);
  bunyi(9, 700);
  bunyi(6, 300);
  bunyi(6, 1000);
  bunyi(0, 1000);

  bunyi(6, 500);
  bunyi(6, 500);
  bunyi(6, 500);
  bunyi(6, 500);
  bunyi(6, 500);
  bunyi(7, 500);
  bunyi(6, 500);
  bunyi(8, 700);
  bunyi(3, 300);
  bunyi(5, 1000);
  bunyi(0, 1000);

  bunyi(8, 500);
  bunyi(7, 700);
  bunyi(8, 300);
  bunyi(9, 700);
  bunyi(7, 350);
  bunyi(8, 1000);
  bunyi(0, 1000);

  bunyi(3, 500);
  bunyi(5, 500);
  bunyi(4, 700);
  bunyi(5, 300);
  bunyi(7, 700);
  bunyi(7, 700);
  bunyi(0, 500);

  bunyi(4, 500);
  bunyi(5, 500);
  bunyi(3, 700);
  bunyi(5, 300);
  bunyi(8, 1000);
  bunyi(0, 500);

  bunyi(3, 500);
  bunyi(5, 500);
  bunyi(4, 700);
  bunyi(5, 300);
  bunyi(9, 1000);
  bunyi(0, 500);

  bunyi(9, 400);
  bunyi(0, 5);
  bunyi(9, 400);
  bunyi(0, 5);
  bunyi(9, 400);
  bunyi(0, 5);
  bunyi(8, 500);
  bunyi(10, 1000);
  bunyi(0, 500);

  bunyi(3, 500);
  bunyi(5, 500);
  bunyi(4, 700);
  bunyi(5, 300);
  bunyi(7, 700);
  bunyi(7, 700);
  bunyi(0, 500);

  bunyi(4, 500);
  bunyi(5, 500);
  bunyi(3, 700);
  bunyi(5, 300);
  bunyi(8, 1000);
  bunyi(0, 500);

  bunyi(3, 500);
  bunyi(5, 500);
  bunyi(4, 700);
  bunyi(5, 300);
  bunyi(9, 1000);
  bunyi(0, 500);

  bunyi(9, 500);
  bunyi(6, 500);
  bunyi(7, 500);
  bunyi(8, 1000);
  bunyi(0, 1000);
}

