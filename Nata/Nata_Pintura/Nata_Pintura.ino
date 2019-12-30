#include <VarSpeedServo.h> 

class Motor
{
  // Class Member Variables
  // These are initialized at startup
  int MotorPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time

  // These maintain the current state
  int MotorState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated

  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Motor(int pin)
  {
  MotorPin = pin;
  pinMode(MotorPin, OUTPUT);     
  
  MotorState = LOW; 
  previousMillis = 0;
  }

  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    randomSeed(analogRead(A1));
    OnTime = random(100,4000);
    randomSeed(analogRead(A2));
    OffTime = random(100,4000);
     
    if((MotorState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      MotorState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(MotorPin, MotorState);  // Update the actual LED
      Serial.println("Moviendo motor");
    }
    else if ((MotorState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      MotorState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(MotorPin, MotorState);   // Update the actual LED
    }
  }
};

class Sweeper
{
  VarSpeedServo servo;              // the servo
  int pos;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position

public: 
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    randomSeed(analogRead(A3));
    updateInterval = random(100,1000);
    
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      randomSeed(analogRead(A1));
      pos = random(60,180);
      servo.write(pos ,random(1,70),true);
      Serial.print("Moviendo servo a: ");
      Serial.println(pos);
    }
  }
};
 
 
Motor Motor1(12);
Motor Motor2(10);
Motor Motor3(5);
Motor Motor4(3);

Sweeper sweeper1(15);
 
void setup() 
{ 
  Serial.begin(9600);
  sweeper1.Attach(8);
} 
 
 
void loop() 
{ 
  sweeper1.Update();
  
  Motor1.Update();
  Motor2.Update();
  Motor3.Update();
  Motor4.Update();
}
