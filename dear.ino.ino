int mesure_distance_cm(byte trig_pin,byte dist_pin)
{
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin,LOW);
  int value = (pulseIn(dist_pin,HIGH)/2)/29.1+2;
  if (value>255) { value=255; }
  delay(20);
  return value;
}

void setup() {
  pinMode(4,OUTPUT);//Sonar triger pin
  pinMode(6,INPUT);//Sonar distance pulse pin
  pinMode(3, OUTPUT);
}

void loop() {
  if (mesure_distance_cm(4,6) > 30) {
    digitalWrite(3, HIGH);

  } else {
    digitalWrite(3, LOW);

  }

}