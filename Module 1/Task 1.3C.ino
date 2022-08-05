const int led = 13;
const int led1 = 12;
const int sensor = 2;
const int button = 3;

volatile int current_state = LOW;
volatile int button_state = LOW;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  
  pinMode(sensor, INPUT);
  pinMode(button, INPUT);
  
  Serial.begin(9600);
 attachInterrupt(digitalPinToInterrupt(sensor), pin_ISR1, CHANGE);
attachInterrupt( digitalPinToInterrupt(button), pin_ISR2, CHANGE);	
}

void loop() {
}

void pin_ISR1(){
   current_state = digitalRead(sensor);
  Serial.println(current_state);
  delay(1000);
  if (current_state == HIGH) {
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}

void pin_ISR2(){
  button_state = digitalRead(button);
  Serial.println(button_state);
  delay(1000);
  if (button_state == HIGH) {
    digitalWrite(led1,HIGH);
  }
  else{
    digitalWrite(led1,LOW);
  }
}
