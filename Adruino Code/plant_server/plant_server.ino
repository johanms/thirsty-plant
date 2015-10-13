
class LevelSensor
{
  int trigPin;
  int echoPin;
  
  int lowRaw;
  int highRaw;
  
  public:
  
  LevelSensor(int tPin, int ePin, int miRaw, int maRaw)
  {
    trigPin = tPin;
    echoPin = ePin;
    lowRaw = miRaw;
    highRaw = maRaw;
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }
  
  int readLevelRaw()
  {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    
    return (int)distance;
  }
  int readLevelPercentage()
  {
    int level = this->readLevelRaw();   
    int range = lowRaw - highRaw;
    int levelPercentage = (int)((100.0/(float)range)*(level-highRaw));
    return 100 - levelPercentage;
  }
  
};


class MoistureSensor
{ 
  int sensorPin;
  
  public:
  
  MoistureSensor(int pin1)
  {
    sensorPin = pin1;
  }
  
  int readMoisturePercentage()
  {
    int sensorValue = analogRead(sensorPin);
    float percentage = (float)sensorValue/1023 * 100;
    return 100 - (int)percentage;
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

class WaterPump
{
  int pumpPin;
  
  public:
  
  WaterPump(int pin)
  {
    pumpPin = pin;
    pinMode(pin, OUTPUT);
  }
  
  void waterMillis(int msec)
  {    
    //should update function and remove delay, use hardware time instead
    digitalWrite(pumpPin, HIGH);
    delay(msec);
    digitalWrite(pumpPin, LOW);
  }
  
};


int command = 0;

LevelSensor LevSens(5, 6, 14, 3);
MoistureSensor MoistSens(0);
RaspberryPiInterface RpiInterface(9600);
WaterPump Pump(10);


void setup(){
 Serial.begin(9600);
 
}

void loop()
{
   if (RpiInterface.avail()) {
     command = RpiInterface.readByte();
     switch (command){
       case 'L':
       //measure level and report
       Serial.println(LevSens.readLevelPercentage());
       break;
       
       case 'M':
       //measure moisture and report
       Serial.println(MoistSens.readMoisturePercentage());
       break;
       
       case 'W':
       //water plant and report
       Pump.waterMillis(500);
       break;
     }
   }
}

