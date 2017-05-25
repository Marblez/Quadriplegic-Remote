const int QRD1114_PIN = A0; // Sensor output voltage
float offset = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); // Enable LED Light Output
}

void loop() 
{
  // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  Serial.println(proximityV);
  delay(1000);

  if(proximityV > offset){
    Serial.println("Trigger the TV");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
  }
}
