// Get Pulse Data and make Serial Commands from it
// Arduino PRO MINI  (Leonardo)
//
//  RC INPUT CHANNEL FROM variable PIN  

//Indicator LED to check if RC is valid
const int ledPin =  17;        // the number of the LED pin
int ledState = LOW;                     // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 400;               // interval at which to blink (milliseconds)

//#define DEBUG //
//#define ACTIVEPIN 2  // Amount of Active Pins
//int activePin[ACTIVEPIN] = {2,3};  //Array with RC Input Pins 

#define ACTIVEPIN 8
int activePin[ACTIVEPIN] = {2,3,4,5,6,7,8,9};  //Array with RC Input Pins 


//Set Comand for each PIN (RC Channel)
//  Commands               2|Wake UP 3|Cantina 4|Smirk 5|OP All  6| Arms OP  7|Arm Test 8| center 9| Mode                
String outHigh[8] = {":SE14",":SE07",":SE03",":OP00","#OPUA/r#OPLA","#OPUA","center","MOD" };
//  Commands                2|Reset 3| MANAMA 4|Wave 5|Flutter 6| Arms CL  7|Arm Test  8| tool1 9| next Sound
String outLow [8] = {"CBD1","manama",":SE04","#OF00","#CLUA/r#CLLA","#CLUA","tool1","$2"};

void getCMD(int PIN){
     
    //Serial.println("Data: ");

    for (int i=0 ; i <= PIN-1; i++){
      
        int value = pulseIn(activePin[i],HIGH);
        #ifdef DEBUG
          Serial.print("index ");
          Serial.print(i);
          Serial.print(" PIN ");
          Serial.print(activePin[i]);
          Serial.print(" val: ");
          Serial.println(value);
        #endif

        if (value <= 1100){
          Serial.print(outLow[i]);
          Serial.println('\r');
          delay(2000);
        }
        if (value >= 1600){
          Serial.print(outHigh[i]);
          Serial.println('\r');
          delay(2000);
        }
   
    }
    
}


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  getCMD(ACTIVEPIN);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
     digitalWrite(ledPin, ledState);
  }
  
}
