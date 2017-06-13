
#include <ss.h>
#include <lss.h>

#include <Lampe.h>
#include <Motor.h>
#include <stdlib.h>


#include <Arduino.h>
#include <SoftwareSerial.h>
#include <MemoryFree.h>

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}


Lampe l1;
Ss dd("");
Ss* str = &dd;

void setup() {
  Serial.begin(9600);
  
    /*char* cc = "{'Motor':{'m4':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m4':{'angle':8000,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m3':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m2':{'angle': 40,'speed':300,'direction':'LEFT','type':'SERVOS'},'m328':{'angle': 40,'speed':300,'direction':'LEFT','type':'SERVOS'}}}";
  dd.setString(cc);
  l1.parseJson(str,0);*/
  
 
  

}

void loop() {
   if (Serial.available() > 0) {
      char cc[500];
      Serial.readString().toCharArray(cc,500);
      Serial.print(F("Le string recu est : "));Serial.println(cc);
      Serial.println(F("--------------------------------------------"));
      dd.setString(cc);
      if(str->getString()[0] == '{'){
        int n = l1.getqMotors();
        Serial.print(F("qMotors : "));Serial.println(n);
        l1.parseJson(str,n);
        l1.affiche();
      }
   }

}
