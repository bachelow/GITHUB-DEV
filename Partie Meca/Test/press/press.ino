#include "DynamixelSerial.h"

/*
le bouton poussoir est connecté au pin 2 pour un mode INPUT_PULLUP
la Led est connectée au pins 4 avec une résistance de 220Ω
*/

//déclaration des variables
int pinBouton;
boolean etatAllumage;

void setup() {

//initialisation des variables
Serial.begin(9600);
 
Dynamixel.begin(1000000,2);
delay(1000);

}

void loop() {
  

  Serial.println("COUCOU");
  Dynamixel.setEndless(254,ON);
  Dynamixel.turn(254,RIGTH,300);


  delay(200);
}



