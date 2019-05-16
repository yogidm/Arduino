/*#define ledPin 13
  int state = 0;
  void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  }
  void loop() {
  if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW); // Turn LED OFF
    Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
    state = 0;
  }
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");;
    state = 0;
  }
  }

*/

/*

  #define ledMerah 2
  #define ledHijau 3
  #define ledBiru 4

  int state = 0;
  void setup() {
  pinMode(ledMerah, OUTPUT);
  digitalWrite(ledMerah, LOW);
  pinMode(ledHijau, OUTPUT);
  digitalWrite(ledHijau, LOW);
  pinMode(ledBiru, OUTPUT);
  digitalWrite(ledBiru, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  }
  void loop() {
  if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
  if (state == '1') {
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledBiru, LOW);

    Serial.println("LED Merah: Nyala");
    state = 0;
  }
  else if (state == '2') {
    digitalWrite(ledMerah,LOW );
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledBiru, LOW);

    Serial.println("LED Hijau: Nyala");
    state = 0;
  }

  else if (state == '3') {
    digitalWrite(ledMerah,LOW );
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledBiru, HIGH);

    Serial.println("LED Biru: Nyala");
    state = 0;
  }
  }

*/



#define ledMerah 3
#define ledHijau 5
#define ledBiru 6

int nilaiR = 0;
int nilaiG = 0;
int nilaiB = 0;

int state = 0;
char dataBlue;

void setup() {
  pinMode(ledMerah, OUTPUT);
  digitalWrite(ledMerah, LOW);
  pinMode(ledHijau, OUTPUT);
  digitalWrite(ledHijau, LOW);
  pinMode(ledBiru, OUTPUT);
  digitalWrite(ledBiru, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if (Serial.available()) { // Checks whether data is comming from the serial port
    dataBlue = Serial.read(); // Reads the data from the serial port

    if (dataBlue == 'R') nilaiR = Serial.parseInt();
    if (dataBlue == 'G') nilaiG = Serial.parseInt();
    if (dataBlue == 'B') nilaiB = Serial.parseInt();
    
  }

   if (dataBlue == '1') {
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledBiru, LOW);

    Serial.println("LED Merah: Nyala");
    state = 0;
  }
  else if (dataBlue == '2') {
    digitalWrite(ledMerah,LOW );
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledBiru, LOW);

    Serial.println("LED Hijau: Nyala");
    state = 0;
  }

  else if (dataBlue == '3') {
    digitalWrite(ledMerah,LOW );
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledBiru, HIGH);

    Serial.println("LED Biru: Nyala");
    state = 0;
  }


  analogWrite(ledMerah, nilaiR);
  analogWrite(ledHijau, nilaiG);
  analogWrite(ledBiru, nilaiB);



}
