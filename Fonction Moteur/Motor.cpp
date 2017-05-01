#include "../headers/Motor.hpp"

//constructeur qui permet de construire des objets avec 0, 1, 2, 3 ou 4 arguments selon les besoins. 
Motor::Motor(Moteur_t type, Direct_t direction, int speed, float angle) : type{ type }, direction{ direction }, speed{ speed }, angle{angle}
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
