
#include "NewPing.h"
#include <Servo.h>

#define TRIGGER_PIN 7
#define ECHO_PIN 8

#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;

int val = 0;

int distance;
void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
}

void loop()
{
  while(1){
    distance = sonar.ping_cm();
    if(distance <= 10) {
      Serial.println(String(val) + "," + String(distance);
    }
    myservo.write(val);
    val+=2;
    delay(30);
    
    
    
    if(val == 180) {
      while(1) {
        
        if(val == 0) {
          break;
        }
        
        distance = sonar.ping_cm();
        myservo.write(val);
        val-=2;
        
        if(distance <= 10) {
        Serial.println(String(val) + "," + String(distance);
        }
        
        delay(30);
        
      }
    }
  }
}
