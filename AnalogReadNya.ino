void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
   int sensorValue = analogRead(A3);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
}
