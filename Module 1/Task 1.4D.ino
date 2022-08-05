const int led = 13;
const int led1 = 12;
const int led2 = 8;
const int led3 = 11;

const int sensor = 2;
const int button = 3;
const int button1 = 7;

volatile int current_state = LOW;
volatile bool D3_state = LOW;
volatile bool D7_state = LOW;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(sensor, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  
  // Disable all interrupts
  noInterrupts();
  
  // Enable PCIE2 Bit3 = 1 (Port D)
  PCICR |= B00000100;
  // Select PCINT23 Bit7 = 1 (Pin D7)
  PCMSK2 |= B10000000;
  
  
  Serial.begin(9600);
 attachInterrupt(digitalPinToInterrupt(sensor), pin_ISR1, CHANGE);
attachInterrupt( digitalPinToInterrupt(button), pin_ISR2, CHANGE);	

  startTimer();
  // Enable all interrupts
  interrupts();
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
  if (digitalRead(button) == LOW) {
    //Pin D3 triggered the ISR on a Falling pulse
    D3_state = !D3_state;
    //Set LED 1 to state of D3_state boolean
    digitalWrite(led1, D3_state);
  }
}

ISR (PCINT2_vect){
  if (digitalRead(button1) == LOW) {
    //Pin D7 triggered the ISR on a Falling pulse
    D7_state = !D7_state;
    //Set LED 2 to state of D7_state boolean
    digitalWrite(led2, D7_state);
  }
}
void startTimer(){
  noInterrupts();
  TCCR1A = 0; // set entire TCCR1A register to 0
  TCCR1B = 0; // same for TCCR1B
  TCNT1  = 0; // initialize counter value to 0
  // set compare match register for 0.5 Hz increments
  OCR1A = 16000000 / (1024 * 0.5) - 1; // (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

ISR(TIMER1_COMPA_vect){
   digitalWrite(led3, digitalRead(led3) ^ 1);
}
