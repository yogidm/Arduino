int servonya = 7;
int i;

void setup() {
     pinMode (servonya, OUTPUT); 
}

void naik1(char j)
{
 for (i=0;i<j;i++){
  
digitalWrite(servonya, HIGH);
delayMicroseconds(1200);
digitalWrite(servonya, LOW);
delay(50);    }     
}

void naik2(char j)
{
 for (i=0;i<j;i++){
digitalWrite(servonya, HIGH);
delayMicroseconds(1500);
digitalWrite(servonya, LOW);
delay(50);    }     
}

void naik3(char j)
{
 for (i=0;i<j;i++){
digitalWrite(servonya, HIGH);
delayMicroseconds(1800);
digitalWrite(servonya, LOW);
delay(50);    }     
}

void naik4(char j)
{
 for (i=0;i<j;i++){
digitalWrite(servonya, HIGH);
delayMicroseconds(2100);
digitalWrite(servonya, LOW);
delay(50);    }     
}
void loop() {
        naik1(10);
        
        naik3(40);
       
       

}
