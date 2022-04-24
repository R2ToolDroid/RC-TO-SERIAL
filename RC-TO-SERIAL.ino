// Get Pulse Data and make Serial Commands from it
// Arduino PRO MINI  (Leonardo)
//
//  RC INPUT CHANNEL FROM variable PIN  

//Indicator LED to check if RC is valid
const int ledPin =  17;        // the number of the LED pin
int ledState = LOW;                     // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 100;               // interval at which to blink (milliseconds)

//#define DEBUG //
//#define ACTIVEPIN 2  // Amount of Active Pins
//int activePin[ACTIVEPIN] = {2,3};  //Array with RC Input Pins 

#define ACTIVEPIN 3
int activePin[ACTIVEPIN] = {2,3,4};  //Array with RC Input Pins 



/* Channel --- Test for Pro PSI @0T7
 *  
 *  1 THROTTLE  LEVEL 1-6 1049
 *  
GEAR   Next Sound    CantinaSE07    LeiaSE08    SmirkSE03       Manamana      FaintSE06     Flutter
    ||-----0-----||-----1-----||-----2-----||-----3-----|    |-----4-----||-----5-----||-----6-----||  
FLAP     Reset       Wave2SE04    AwakeSE14     SPRAY            FLUTTER     

*/
//Set Comand for each PIN (RC Channel)
              
String out1 [7] = {  "$2",":SE07",  ":SE08" ,":SE03", "manama", ":SE06", "#OF00" };
String out2 [7] = {  ":SE10",":SE04", ":SE14","#SAON", ":OP00", "MOD", "#SPRAY" };

int level= 0;

// Check in Range inRange(x, 0, 200)
bool inRange(int val, int minimum, int maximum)
{
  return ((minimum <= val) && (val <= maximum));
}


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
          Serial.print(value);
          Serial.print(" LEVEL: ");
          Serial.println(level);
          
        #endif
        

        if(value <= 600){
          return;
        }

        if (i == 0){

          if(inRange(value, 1035,1120)) level = 0;
          if(inRange(value, 1121,1250)) level = 1;
          if(inRange(value, 1251,1350)) level = 2;
          if(inRange(value, 1351,1500)) level = 3;
          if(inRange(value, 1501,1620)) level = 4;
          if(inRange(value, 1620,1750)) level = 5;
          if(inRange(value, 1751,1870)) level = 6;
          //if(inRange(value, 1751,1870)) level = 8; 

        
          
          
        }
        /*
        if (value <= 1100){
          Serial1.print(outLow[i]);
          Serial1.print('\r');
          delay(2000);
        }
        */
        if ((value >= 1600)&&(i ==1)){
          Serial1.print(out1[level]);
          //Serial.print(out1[level]);
          Serial1.print('\r');
          delay(1000);
        }
        if ((value >= 1600)&&(i ==2)){
          Serial1.print(out2[level]);

          //Serial.print(out2[level]);
          
          Serial1.print('\r');
          delay(1000);
        }
       
    }
    
}


void setup() {
  // put your setup code here, to run once:
    //Serial.begin(9600);
    Serial1.begin(9600);
    //Serial1.begin(115200);
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

   //Serial.print("CBD1/r");
   //delay(4000);
  
}
