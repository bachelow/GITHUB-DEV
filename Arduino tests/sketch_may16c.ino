#include <Lampe.h>
#include <Motor.h>

#include <SoftwareSerial.h>
#include <Arduino.h>


void setup() {
    Serial.begin(9600);
    Motor m2(SERVOS,RIGHT,0,0,"m1");
    Motor tbm[] = {};
    String tbc[] = {};
    String cc = "Motor";
    
    String* tbcc = Lampe::push_backc(0,cc,tbc);
    Lampe l1;
    l1.settabMoteur(tbm);
    l1.settabclass(tbc);
    l1.settabMoteur(Lampe::push_backm(0,m2,l1.gettabMoteur()));
    String text = "{'Motor':{'m4':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},{'m4':{'angle':8000,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m3':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m2':{'angle': 40,'speed':30,'direction':'LEFT','type':'SERVOS'}}}";
    String txt;
    txt = "'angle': 90,'speed':40,'direction':'RIGHT','type':'STEPPERS'";
    l1.parseJson(text,1);
    l1.affiche();
    

   
}

void loop() {

}
