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
  Motor(int pin, long on, long off)
  {
  MotorPin = pin;
  pinMode(MotorPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  MotorState = LOW; 
  previousMillis = 0;
  }

  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((MotorState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      MotorState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(MotorPin, MotorState);  // Update the actual LED
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
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
  }
};
 
 
Motor Motor1(12, 123, 400);
Motor Motor2(10, 350, 350);
Motor Motor3(5, 200, 222);
Motor Motor4(3, 200, 222);

Sweeper sweeper1(15);
 
void setup() 
{ 
  Serial.begin(9600);
  sweeper1.Attach(7);
} 
 
 
void loop() 
{ 
  sweeper1.Update();
  
  Motor1.Update();
  Motor2.Update();
  Motor3.Update();
  Motor4.Update();
}
