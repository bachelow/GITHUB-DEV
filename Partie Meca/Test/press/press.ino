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
pinBouton = 4;
etatAllumage=0;
//définition des modes
pinMode(pinBouton, INPUT_PULLUP);
 
Dynamixel.begin(1000000,2);
delay(1000);

}

void loop() {

Serial.print(etatAllumage);
  
if (etatAllumage) //on teste si etatAllumage est à 1
{
    Dynamixel.turn(254,LEFT,300);

}
else //sinon
{
    Dynamixel.turn(254,RIGTH,300);
}
//lecture de l'état du bouton et stockage dans etatBouton
boolean etatPinBouton = digitalRead(pinBouton);
Serial.println(etatPinBouton);
//test des conditions
if (!etatPinBouton)//si bouton appuyé (donc le pin indique 0 car il est en mode INPUT_PULLUP)
{
    if (etatAllumage) //si etatAllumage à 1
    {
      etatAllumage=0; //on le passe à 0
    }
    else //sinon
    {
      etatAllumage=1; //on le passe à 1
    }
}
delay(200);
}



