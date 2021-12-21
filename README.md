# RC-TO-SERIAL
 RC Command Translator
 Send MABC Commands to your Droid via RC Transmitter
 
 
## PINS for use with Arduino Pro Micro
* 2 - 12  RC Input
* 0 TX for 9600 Baud Output
* PIN  2-3-4-5-6-7-8-9

* //  Commands        -2|Wake UP -3|Cantina -4|Smirk -5|OP A -6|UArmOP -7|Wave -8|center -9|Mode                
* String outHigh[8] = {":SE14",":SE07",":SE03",":OP00","OPA",":SE01","center","MOD" };
* //  Commands        -2|Reset -3|MANAMA -4|Wave -5|Flutter -6|Arms CL  -7|Scream -8|tool1 -9|next Sound
* String outLow [8] = {"CBD1","manama",":SE04","#OF00","CLA",":SE01","tool1","$2"};

## CH SET
* CH8   232 Trig

* CH11  Wake uP - Reset
* CH12  Cantina - Manama
* CH13  Smirk - Wave
* CH14  OP ALL - Flutter

* CH10  Arms OP - Arms CL
* CH9   Wave - Scream
* CH6   center - tool1
* CH5   Mode  - Next Sound

* CH7   Source RC or Stick 



![RC Carson Channels](carson-channels.png?raw=true "RC Setup")
