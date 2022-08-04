const int led = 13;
const int sensor = 2;

int currentstate = LOW;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentstate = digitalRead(sensor);
  Serial.println(currentstate);
  delay(1000);
  if (currentstate == HIGH) {
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

}