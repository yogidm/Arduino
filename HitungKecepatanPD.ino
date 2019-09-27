int sensorState, sensorState2;
int hit, mulai;
int jarak = 150.0; //mm
void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  if (sensorValue >= 100)
  { sensorState = 1;
    mulai = 1;
  }
  else {
    sensorState = 0;
  }
  if (sensorValue2 >= 100)
  { sensorState2 = 1;
    mulai = 0;
  }
  else {
    sensorState2 = 0;
  }

  if (mulai == 1)
  { hit++;
  }
  if (mulai == 0)
  { hit = hit;
  }
  float kec = jarak / hit;
  Serial.print(sensorState);
  Serial.print('-');
  Serial.print(sensorState2);
  Serial.print('-');
  Serial.print(hit);
  Serial.print('-');
  Serial.print(kec);
  Serial.println(" mm/ms");
  delay(10);
}
