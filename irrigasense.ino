#include<ESP32Servo.h>

#define soil 34
#define moistureTreshold 1000
#define relay 5


Servo myservo;

void setup() {
  myservo.write(0);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGHP  );
  Serial.begin(9600);
  myservo.attach(4);
}

void loop() {
  delay(2000); // Wait a few seconds between measurement
  
  // Read moisture 
  float moisture = analogRead(soil);

  Serial.print("  Moisture: ");
  Serial.println(moisture);

  if(moisture>moistureTreshold){
    Serial.println("low moisture detected");
    myservo.write(180);
    digitalWrite(relay,LOW);                                    
  }
  else{
    myservo.write(0);
    digitalWrite(relay,HIGH);
  }
}
