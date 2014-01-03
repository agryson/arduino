const int redPin = 9;
const int greenPin = 11;
const int bluePin = 10;

const int redSense = A0;
const int greenSense = A1;
const int blueSense = A2;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;

int redSenseVal = 0;
int greenSenseVal = 0;
int blueSenseVal = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  redSenseVal = analogRead(redSense);
  delay(5);
  greenSenseVal = analogRead(greenSense);
  delay(5);
  blueSenseVal = analogRead(blueSense);
  delay(5);
  
  Serial.print("\t Raw Sensor Values \t Red: ");
  Serial.print(redSenseVal);
  Serial.print("\t Green: ");
  Serial.print(greenSenseVal);
  Serial.print("\t Blue: ");
  Serial.print(blueSenseVal);
  
  redVal = redSenseVal/4;
  greenVal = greenSenseVal/4;
  blueVal = blueSenseVal/4;
    
  Serial.print("\t Mapped Sensor Values \t Red: ");
  Serial.print(redVal);
  Serial.print("\t Green: ");
  Serial.print(greenVal);
  Serial.print("\t Blue: ");
  Serial.print(blueVal);
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
