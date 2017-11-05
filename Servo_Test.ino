int servonya = 7;
int i;

void setup() {
  // put your setup code here, to run once:

pinMode (servonya, OUTPUT);
}

void naik(char j)
{
 for (i=0;i<j;i++){
  
digitalWrite(servonya, HIGH);
delayMicroseconds(1400);
digitalWrite(servonya, LOW);
delay(50);    }     
}

void turun(char j)
{
 for (i=0;i<j;i++){
  
digitalWrite(servonya, HIGH);
delayMicroseconds(1900);
digitalWrite(servonya, LOW);
delay(50);    }     
}

void loop() {
  // put your main code here, to run repeatedly:
naik(20);
turun(20);

}
