#ifndef __MOTOR__HPP__
#define __MOTOR__HPP__
#include <iostream>
#include <string>

typedef enum{LEFT,RIGHT} Direct_t;
typedef enum{STEPPERS, SERVOS} Moteur_t;

class Motor{
    private :
        Direct_t direction;
        Moteur_t type;
		int speed;
        float angle;
        std::string name;

    public :
		Motor(Moteur_t type = STEPPERS, Direct_t direction = LEFT, int speed = 0, float angle = 0,std::string name = "");
		~Motor();

		//setters & getters
        int getSpeed();
        void setSpeed(int);
        Direct_t getDir();
        void setDir(Direct_t);
        float getAngle();
        void setAngle(float);
        void tourner(int ID, Direct_t side, int speed);
        std::string getName();
        void setName(std::string);
        Moteur_t getType();
        void setType(Moteur_t);
};

#endif
