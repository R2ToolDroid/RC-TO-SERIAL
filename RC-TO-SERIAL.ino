// Get Pulse Data and make Serial Commands from it
// Arduino PRO MINI  (Leonardo)
//
//  RC INPUT CHANNEL FROM variable PIN  

//Indicator LED to check if RC is valid
const int ledPin =  LED_BUILTIN;        // the number of the LED pin
int ledState = LOW;                     // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;               // interval at which to blink (milliseconds)

#define ACTIVEPIN 2  // Amount of Active Pins

int activePin[ACTIVEPIN] = {2,4};  //Array with RC Input Pins 

//Set Comand for each PIN (RC Channel)

String outHigh[ACTIVEPIN] = {"zweiH","vierH"};
String outLow [ACTIVEPIN] = {"zweiL","vierL"};

void getCMD(int PIN){
     
    //Serial.println("Data: ");

    for (int i=0 ; i <= PIN-1; i++){
      
        int value = pulseIn(activePin[i],HIGH);
       // Serial.print("index ");
        //Serial.print(i);
        //Serial.print(" PIN ");
        //Serial.print(activePin[i]);
        //Serial.print(" val: ");
        //Serial.println(value);

        if (value <= 1200){
          Serial.println(outLow[i]);
          Serial.print('\r');
          delay(2000);
        }
        if (value >= 1500){
          Serial.println(outHigh[i]);
          Serial.print('\r');
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
