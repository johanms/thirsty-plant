
#include <Servo.h>

Servo servo1;

int command = 0;

void setup(){
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  
  servo1.attach(11);
}

void loop(){
  if (Serial.available()) {
    command = Serial.read();
    if (command == 'T'){
    //digitalWrite(8, HIGH); 
    servo1.write(0);
    }
    else if(command == 'F'){
      //digitalWrite(8, LOW);
      servo1.write(90);
    }
    Serial.println("character recieved:");
  }
}
