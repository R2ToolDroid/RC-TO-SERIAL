# RC-TO-SERIAL
 RC Command Translator
## PINS for use with Arduino Pro Micro
* 2 - 12  RC Input
* 0 TX for 9600 Baud Output
* PIN  2-3-4-5-6-7-8-9
*   
//  Commands               2|Wake UP 3|Cantina 4|Smirk 5|OP All  6| Arms OP  7|Arm Test 8| center 9| Mode                
String outHigh[8] = {":SE14",":SE07",":SE03",":OP00","#OPUA/r#OPLA","#OPUA","center","MOD" };
//  Commands                2|Reset 3| MANAMA 4|Wave 5|Flutter 6| Arms CL  7|Arm Test  8| tool1 9| next Sound
String outLow [8] = {"CBD1","manama",":SE04","#OF00","#CLUA/r#CLLA","#CLUA","tool1","$2"};


![RC Carson Channels](/blob/main/carson-channels.png?raw=true "RC Setup")
