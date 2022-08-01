const int sensorPin = A0;    // the sensor pin
const int ledPin = 9;        // the LED pin

// variables:
int sensorValue = 0;         // the sensor value


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(9600);

}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);

// if the sensor got the value < 300 then the LED is on else the 
  // led is off
  if(sensorValue < 300){
	analogWrite(ledPin, HIGH);
  }
  else {
    analogWrite(ledPin, LOW);
  }
  // experimenting with the sensor's value to find range:
	Serial.print(sensorValue);
	Serial.print("\t");
  // delay a little bit
  delay(50);
}	