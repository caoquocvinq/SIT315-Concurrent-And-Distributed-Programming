const int led = 13;
const int sensor = 2;

int currentstate = LOW;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
 attachInterrupt(0, pin_INTERRUPT, CHANGE);

}

void loop() {
}

void pin_INTERRUPT(){
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