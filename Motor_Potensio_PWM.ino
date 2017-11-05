int enA = 13;
int n1 = 50;
int n2 = 52;
void setup() {
pinMode(enA,OUTPUT);
pinMode(n1,OUTPUT);
pinMode(n2, OUTPUT);
Serial.begin(9600);
}
void loop() {
//int potensio = analogRead(A0)/4;  
digitalWrite(n1,LOW);
digitalWrite(n2,HIGH);
analogWrite(enA,180);
delay(200);

//digitalWrite(n1,HIGH);
//digitalWrite(n2,LOW);
//analogWrite(enA,120);
//delay(100);

for (int i = 0;i<2;i++)
{
  digitalWrite(n1,HIGH);
digitalWrite(n2,LOW);
analogWrite(enA,180);
delay(100);
  }
}
