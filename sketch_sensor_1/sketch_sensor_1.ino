int sensorPin = A0;
int sensorValue = 0;
int resistorValue = 0;

int sensorMin = 0;
int sensorMax = 1023;

void setup() {                
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  
  // Treshhold
  int range = map(sensorValue, sensorMin, sensorMax, 0, 3);

  switch (range) {
  case 0:    // your hand is on the sensor
    Serial.println(" - sehr hell");
    break;
  case 1:    // your hand is close to the sensor
    Serial.println(" - hell");
    break;
  case 2:    // your hand is a few inches from the sensor
    Serial.println(" - medium");
    break;
  case 3:    // your hand is nowhere near the sensor
    Serial.println(" - dunkel");
    break;
  } 
  
  delay(1000);
}

