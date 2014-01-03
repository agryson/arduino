int notes[] = {262,294,330,349};

void setup(){
  Serial.begin(9600);
}

void loop(){
  int keyVal = analogRead(A0);
  Serial.print(keyVal);
  Serial.println();  
  if(keyVal == 1023){
      tone(8, notes[0]);
  } else if(keyVal <= 1010 && keyVal >= 990){
      tone(8, notes[1]);
  } else if(keyVal <= 515 && keyVal >= 505){
      tone(8, notes[2]);
  } else if(keyVal <= 15 && keyVal >= 3){
      tone(8, notes[3]);
  } else {
      noTone(8);
  }

}
