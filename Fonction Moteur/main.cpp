#include <iostream>
#include "../headers/Motor.hpp"

using namespace std;

int main () {
    Motor m1(SERVOS);
	cout << "speed : " << m1.getSpeed() << endl; //0
    cout << "dir : " << m1.getDir() << endl; //LEFT
	cout << "angle : " << m1.getAngle() << endl; //0

	m1.setSpeed(10);
	m1.setDir(RIGHT);
	m1.setAngle(15.3);

	cout << endl;
	cout << "speed : " << m1.getSpeed() << endl; //10
	cout << "dir : " << m1.getDir() << endl; //RIGHT
	cout << "angle : " << m1.getAngle() << endl; //15.3

	if (m1.getDir() == RIGHT) { //comparaison à la constante -> pas besoin de string
		cout << "Direction droite." << endl;
	}

	return 0;
}
