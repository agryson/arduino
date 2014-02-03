int led = 8;
int sensor = A0;
int initial;
int final;
int delta
;

void setup(){
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop(){
  initial = analogRead(sensor); //Get ambient light
  delay(5);
  digitalWrite(led, HIGH); //turn on lamp
  delay(5);
  final = analogRead(sensor); //Get ambient light + lamp feedback
  delay(5);
  digitalWrite(led, LOW); //turn off lamp
  delay(5);
  delta = final - initial; //get the difference
  Serial.print(delta);
  if(delta > 100){ //if greater than threshold, light up test LED
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
}
