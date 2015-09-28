
#include<Servo.h>

#define trigPin 13
#define echoPin 12

int command = 0;
long level = 0;

Servo ser;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    switch (command){
      case 'L':
        //measure level and report
        level = measureLevel(trigPin, echoPin);
        Serial.println(level);
        break;
      case 'M':
        //measure moisture and report
        break;
      case 'W':
        //water plant and report
        waterPlant();
        break;
    }
  }
}


long measureLevel(int tPin, int ePin){
  long duration, distance;
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  duration = pulseIn(ePin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

void waterPlant(){

}

