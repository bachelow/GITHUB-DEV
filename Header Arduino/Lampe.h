#ifndef LAMPE_H
#define LAMPE_H

#include "Motor.h"
#include <Arduino.h>

class Lampe
{
    public:
        Lampe();
        void addMotor();
        void parseJson(String&, int);
        ~Lampe();
        void affiche();

        //ParseJson function
        static void find_onechar_and_remove(String&,char);
        static void find_allchar_and_remove(String&,char);
        static String until_find_charac(String&,char,bool);
        static void find_acc(int&,char&,String&);
        static bool find_vector(int, Motor*, String&, int&);
        static void maj(Motor*, int , Moteur_t, Direct_t, int, float);
        static void getvalue(String& ,Moteur_t&, Direct_t&, int&, float&);

        //Vector
        static Motor* push_backm(int,Motor, Motor*);
        static String* push_backc(int,String, String*);



        //get/set
        Motor* gettabMoteur();
        String* gettabclass();
        String getfeedBack();
        int getqMotors();
        void settabMoteur(Motor*);
        void settabclass(String*);
        void setfeedback(String);
        void setqMOtors(int);

    private:
        Motor* tabMoteur;
        String* tabclass;
        int qMotors=0;
        String feedBack;
};

#endif // LAMPE_H
