#ifndef __MOTOR__H__
#define __MOTOR__H__
#include <Arduino.h>

typedef enum{LEFT,RIGHT} Direct_t;
typedef enum{STEPPERS, SERVOS} Moteur_t;

class Motor{
    private :
        Direct_t direction;
        Moteur_t type;
		int speed;
        float angle;
        String name;

    public :
		Motor(Moteur_t type = STEPPERS, Direct_t direction = LEFT, int speed = 0, float angle = 0,String name = "");
		~Motor();

		//setters & getters
        int getSpeed();
        void setSpeed(int);
        Direct_t getDir();
        void setDir(Direct_t);
        float getAngle();
        void setAngle(float);
        void tourner(int ID, Direct_t side, int speed);
        String getName();
        void setName(String);
        Moteur_t getType();
        void setType(Moteur_t);

        //tourner
        void tourner(String, String, double, int);
        static double positions(angle);
};

#endif
