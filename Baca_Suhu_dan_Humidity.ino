#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Gagal bacanya masbro, err="); Serial.println(err); delay(1000);
    return;
  }
  Serial.print("Suhu: ");
  Serial.print((int)temperature); Serial.print(" C, ");
  Serial.print("Kelembapan: ");
  Serial.print((int)humidity); Serial.println(" H");

  delay(200);
}
