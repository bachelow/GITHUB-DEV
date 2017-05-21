#include "Motor.h"
#include <Arduino.h>

//constructeur qui permet de construire des objets avec 0, 1, 2, 3 ou 4 arguments selon les besoins.
Motor::Motor(Moteur_t type, Direct_t direction, int speed, float angle, String name) : type{ type }, direction{ direction }, speed{ speed }, angle{angle}, name{name}
{

}

Motor::~Motor() {
	//vide car pas de variables d'instances dynamiques
}

int Motor::getSpeed() {
    return speed;
}

void Motor::setSpeed(int s) {
    speed = s;
}

Direct_t Motor::getDir() {
    return direction;
}

void Motor::setDir(Direct_t dir) {
    direction = dir;
}

float Motor::getAngle() {
    return angle;
}

void Motor::setAngle(float angle) {
    this->angle = angle;
}

void Motor::tourner(int ID, Direct_t side, int speed){

}

void Motor::setName(String name){
    this->name = name;
}

String Motor::getName(){
    return this->name;
}
void Motor::setType(Moteur_t type){
    this->type = type;
}
Moteur_t Motor::getType(){
    return this->type;
}
