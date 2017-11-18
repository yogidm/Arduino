#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  //baca pake read2
  if ((err = dht11.read2(pinDHT11, &temperature, &humidity,NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Gagal bacanya masbro, err="); Serial.println(err); delay(1000);
    return;
  }
  Serial.print("Suhu: ");
  Serial.print(temperature); Serial.print(" C, ");
  Serial.print("Kelembapan: ");
  Serial.print(humidity); Serial.println(" H");

  delay(200);
}
