const int driveEnable = 2;
const int steerEnable = 3;
const int driveControl1 = 4;//1LOW2HIGH=Forward  1HIGH2LOW=Reverse
const int driveControl2 = 5;
const int steerControl1 = 6;//1LOW2HIGH=RIGHT  1HIGH2LOW=LEFT
const int steerControl2 = 7;
const int leftEye = A0;
const int eye = A1;
const int rightEye = A2;

int leftLevel;
int rightLevel;
int frontLevel;

void setup(){
  pinMode(driveEnable, OUTPUT);
  pinMode(steerEnable, OUTPUT);
  pinMode(driveControl1, OUTPUT);
  pinMode(driveControl2, OUTPUT);
  pinMode(steerControl1, OUTPUT);
  pinMode(steerControl2, OUTPUT);
  pinMode(leftEye, INPUT);
  pinMode(eye, INPUT);
  pinMode(rightEye, INPUT);
}

void loop(){
  digitalWrite(steerEnable, HIGH);
  delay(200);
  switch(lookAround()){
    case 1:
      digitalWrite(steerControl1, HIGH);//Left
      digitalWrite(steerControl2, LOW);
      delay(200);
      drive(1000);
      break;
    case 2:
      digitalWrite(steerControl1, LOW);//Right
      digitalWrite(steerControl2, HIGH);
      delay(200);
      drive(1000);
      break;
    case 3:
      digitalWrite(steerEnable, LOW);
      delay(200);
      drive(3000);
      break;
  }
}

int lookAround(){
  leftLevel = analogRead(leftEye);
  rightLevel = analogRead(rightEye);
  frontLevel = analogRead(eye);
  int highest = 0;
  if(leftLevel > rightLevel && leftLevel > frontLevel){
    return 1;
  } else if(rightLevel > frontLevel && rightLevel > leftLevel){
    return 2;
  } else {
    return 3  ;
  }
}

void drive(int time){
  digitalWrite(driveEnable, HIGH);
  digitalWrite(driveControl1, LOW);//Right
  digitalWrite(driveControl2, HIGH);
  delay(time);
  digitalWrite(driveEnable, LOW);

}
