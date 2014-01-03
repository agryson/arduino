int switchState = 0;

void setup(){
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop(){
  switchState = digitalRead(2);

  if(switchState == LOW){
    digitalWrite(3, HIGH);//green LED
    digitalWrite(4, LOW);//red LEDs
    digitalWrite(5, LOW);
  } 
  else {
    digitalWrite(3, LOW);//green LED
    digitalWrite(4, HIGH);//red LEDs
    digitalWrite(5, LOW);
    
    delay(250);
    digitalWrite(4, LOW);//red LEDs
    digitalWrite(5, HIGH);
    delay(250);
  }
}



