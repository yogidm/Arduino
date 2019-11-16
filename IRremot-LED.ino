#include <IRremote.h>

int RECV_PIN = 10;
int biru = 4;
int hijau = 3;
int merah = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(biru, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(merah, OUTPUT);

}


void loop() {
  if (irrecv.decode(&results)) {
    delay(300);
    long int decCode = results.value;
    //switch case untuk memberikan perintah ketika menerima kode tombol
    switch (results.value) {

      case 16724175: //tombol 1
        digitalWrite(biru, HIGH);
        break;

      case 16718055: //tombol 2
        digitalWrite(hijau, HIGH);
        break;

      case 16743045: //tombol 3
        digitalWrite(merah, HIGH);
        break;

      case 1886396639: //tombol 4
        digitalWrite(biru, LOW);
        break;

      case 1886429279: //tombol 5
        digitalWrite(hijau, LOW);
        break;

      case 1886412959: //tombol 6
        digitalWrite(merah, LOW);
        break;

      case 16730805: //tombol 7
        digitalWrite(merah, HIGH);
        digitalWrite(biru, HIGH);
        delay(100);
        digitalWrite(merah, LOW);
        digitalWrite(biru, LOW);
        delay(100);
        digitalWrite(merah, HIGH);
        digitalWrite(hijau, HIGH);
        delay(100);
        digitalWrite(merah, LOW);
        digitalWrite(hijau, LOW);
        delay(100);
        break;

      case 1886392559: //tombol 8
        digitalWrite(merah, HIGH);
        digitalWrite(hijau, HIGH);
        delay(100);
        digitalWrite(merah, LOW);
        digitalWrite(hijau, LOW);
        delay(100);
        break;

      case 1886425199: //tombol 9
        digitalWrite(merah, HIGH);
        digitalWrite(biru, HIGH);
        delay(100);
        digitalWrite(merah, LOW);
        digitalWrite(biru, LOW);
        break;
    }
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
  }
}
