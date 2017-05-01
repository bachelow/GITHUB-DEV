#include "DynamixelSerial.h"



void setup()
{

Dynamixel.begin(1000000,2);
delay(1000);

} 

void loop(){

//Creer nouvelle ID
//Dynamixel.setID(ID,newID);

//Bouge aux positions indiquées
//Avec controle de la vitesse
//moveSpeed(ID, position, vitesse)

//Dynamixel.moveSpeed(20,400,200);
//delay(2000);
//Dynamixel.moveSpeed(20,512,200);
//delay(2000);
//Dynamixel.moveSpeed(20,300,200);
//delay(2000);
//}

// Tourne à gauche puis à droite
//turn(ID, direction, vitesse)

//Dynamixel.turn(20,LEFT,300);
//delay(2000);
//Dynamixel.turn(20,RIGTH,300);
//delay(2000);
//}

//Mettre le mode continu sinon la fonction du dessus
//Ne marche pas

//Permet de mettre le mode continu
//(ON  OFF)
//Attention mode continu seulement pour "turn"

//Dynamixel.setEndless(20,OFF);
//Dynamixel.setEndless(10,OFF);
//}

//Bouge aux positions indiquées
//move(ID, position)

//Dynamixel.move(10,256);
//delay(3000);
//Dynamixel.move(10,768);
//delay(3000);
//Dynamixel.move(10,512);
//delay(3000);
//}




