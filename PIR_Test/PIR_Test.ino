//PIR SENSOR TEST

int sensorState = 0;
int counter = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.write("Started \n");
}

void loop()
{
  // read the state of the sensor/digital input
  sensorState = digitalRead(2);
  // check if sensor pin is HIGH. if it is, set the
  if (sensorState == HIGH) {
    counter++;
    digitalWrite(LED_BUILTIN, LOW);
    delay(1);
  } else {
    if(counter != 0){
      Serial.println(counter);
    }
    counter = 0;
    digitalWrite(LED_BUILTIN, HIGH);
  }
}