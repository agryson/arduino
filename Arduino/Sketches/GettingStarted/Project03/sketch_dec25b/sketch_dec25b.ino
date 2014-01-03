const int sensorPin = A0;
const float baseline = 21.78;

void setup(){
  Serial.begin(9600);
  for(int pinNum = 2; pinNum < 5; pinNum++){
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop(){
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  float voltage = (sensorValue/1024.0)*5.0;
  Serial.print(", Voltage: ");
  Serial.print(voltage);

  float temp = (voltage - .5)*100;
  Serial.print(", ");
  Serial.print(temp);
  Serial.print("C, ");

  if(temp < baseline + 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if( temp >= baseline + 2 && temp < baseline + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temp >= baseline+4 && temp < baseline + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);    
  } else if(temp >= baseline+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);    
  }
  delay(1000);
}

