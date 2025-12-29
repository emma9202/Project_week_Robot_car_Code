#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX | TX
int command ;

void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);
   Serial.println("You're connected via Bluetooth");

   pinMode(13,OUTPUT);  
   pinMode(12,OUTPUT);  
   pinMode(11,OUTPUT);  
   pinMode(10,OUTPUT);   
}

void loop() {
   if (mySerial.available()) {
      command = mySerial.read();

      if (command == 'F') {
         Serial.println("Forward");
         void forward();
      }

      else if (command == 'B') {
         Serial.println("Reverse");
         void backwards();
      }

      else if (command == 'L') {
         Serial.println("Left");
         void left();

      }

      else if (command == 'R') {
         Serial.println("Right");
         void right();
      }

      else if (command == 'S') {
         Serial.println("Stop");
         void stop();
      }
      
      delay(30);
   }
   void forward(){
         digitalWrite(13, LOW);   
         digitalWrite(12, HIGH);  
         digitalWrite(11, HIGH);
         digitalWrite(10, LOW);
   }

   void backwards(){
         digitalWrite(13, HIGH); 
         digitalWrite(12, LOW);   
         digitalWrite(11, LOW);
         digitalWrite(10, HIGH);
   }

   void left(){
         digitalWrite(13, LOW);    
         digitalWrite(12, LOW);
         digitalWrite(11, HIGH);
         digitalWrite(10, LOW);
   }

   void rght(){
         digitalWrite(13, LOW);   
         digitalWrite(12, HIGH);
         digitalWrite(11, LOW);
         digitalWrite(10, LOW);
   }

   void stop(){
         digitalWrite(13, LOW);
         digitalWrite(12, LOW);
         digitalWrite(11, LOW);
         digitalWrite(10, LOW);
   }
}