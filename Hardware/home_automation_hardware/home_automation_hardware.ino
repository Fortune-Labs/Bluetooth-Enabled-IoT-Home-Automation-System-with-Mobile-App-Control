#include <SoftwareSerial.h>
//define constants for transmit and receive
const int rxPin = 2;
const int txPin = 3;
SoftwareSerial mySerial(rxPin, txPin);

//define constants for home devices
const int bulb      = 5;
// const int bulb2      = 6;
const int fan       = 7;          

//define state of input from mobile device
int state = 0;

void setup() {
  pinMode(bulb,OUTPUT);
  // pinMode(bulb2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
    if(Serial.available() > 0){
      state = Serial.read();
      bulb_func();
      fan_func();

    }
}

//BULB1 STUFF
void bulb_func(){
    if (state == '1'){
        digitalWrite(bulb, HIGH);
        Serial.println("Bulb is ON");
    }
    else if (state == '0'){
        digitalWrite(bulb, LOW);
        Serial.println("Bulb is OFF"); 
    }
}

//FAN STUFF
void fan_func(){
    if (state == '2'){
        digitalWrite(fan, HIGH);
        Serial.println("Fan Opened");
    }
    else if (state == '3'){
        digitalWrite(fan, LOW); 
        Serial.println("fan turned off"); 
    }  
}

// //BULB1 STUFF
// void bulb_func(){
//     if (state == '1'){
//         digitalWrite(bulb, HIGH);
//         Serial.println("Bulb is ON");
//     }
//     else if (state == '0'){
//         digitalWrite(bulb, LOW);
//         Serial.println("Bulb is OFF"); 
//     }
// }


