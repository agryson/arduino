#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int count = 0;
float tempRaw;
float temp;
float temp5secs;
float lightRaw;
float light;
int tempAverage[] = {0,0,0,0,0};

void setup(){
  lcd.begin(16,2);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop(){
  //Show that we're working
  if(count<5){
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(8,LOW);
    if(count%2){
      digitalWrite(9,HIGH);
      digitalWrite(13,LOW);
    }else{
      digitalWrite(9,LOW);
      digitalWrite(13,HIGH);
    }
  }
  //get temp and average it over 5 seconds
  tempRaw = analogRead(A0);
  temp = (((tempRaw/1024)*5)-0.5)*100;
  for(int x=0;x<4;x++){
    tempAverage[x] = tempAverage[x+1];
  }
  tempAverage[4] = temp;
  for(int y=0;y<4;y++){
    temp+=tempAverage[y];
  }
  temp = temp/5;
  //Don't average light since it doesn't seem to fluctuate much
  lightRaw = analogRead(A1);
  light = (lightRaw/1023)*100;
  
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("'C");
  lcd.setCursor(0,1);
  lcd.print("Light: ");
  lcd.print(light);
  lcd.print("%");
  
  delay(1000); //second by second updates should be enough

  count++;
}
