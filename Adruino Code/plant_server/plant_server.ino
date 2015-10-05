
#include<Servo.h>

class LevelSensor
{
  int trigPin;
  int echoPin;
  
  public:
  
  LevelSensor(int tPin, int ePin)
  {
    trigPin = tPin;
    echoPin = ePin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }
  
  long getLevel()
  {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    return distance;
  }
};

//Only skeleton class for now
class MoistureSensor
{
 
  int somePin;
  
  public:
  
  MoistureSensor(int pin1)
  {
    somePin = pin1;
  }

};

class RaspberryPiInterface
{

  public:
  
  RaspberryPiInterface(int bitrate)
  {
    Serial.begin(bitrate);
  }
  
  bool avail()
  {
    return Serial.available();
  }
  
  int readByte()
  {
    return Serial.read();
  }
};


int command = 0;
long level = 0;

LevelSensor levSens(12, 13);
MoistureSensor moistSens(11);
RaspberryPiInterface rpiInterface(9600);

void setup(){}

void loop()
{
  if (rpiInterface.avail()) {
    command = rpiInterface.readByte();
    switch (command){
      case 'L':
        //measure level and report
        level = levSens.getLevel();
        //Serial.println(level);
        break;
      case 'M':
        //measure moisture and report
        break;
      case 'W':
        //water plant and report
        break;
    }
  }
}
