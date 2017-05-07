#ifndef LAMPE_H
#define LAMPE_H
#include <vector>
#include "../headers/Motor.hpp"
#include <iostream>
#include <string>

class Lampe
{
    public:
        Lampe();
        void addMotor();
        void parseJson(std::string);
        ~Lampe();

        //ParseJson function
        static void find_onechar_and_remove(std::string&,char);
        static void find_allchar_and_remove(std::string&,char);
        static std::string until_find_charac(std::string&,char,bool);
        static void find_acc(int&,char&,std::string);
        static bool find_vector(std::vector <Motor>, std::string, int& i);
        static void maj(std::vector <Motor>&, int i,Moteur_t,Direct_t,int,float);
        static void getvalue(std::string ,Moteur_t&, Direct_t&, int&, float&);

        //get/set
        std::vector <Motor> gettabMoteur();
        std::vector <std::string> gettabclass();
        std::string getfeedBack();
        int getqMotors();
        void settabMoteur(std::vector <Motor>);
        void settabclass(std::vector <std::string>);
        void setfeedback(std::string);
        void setqMOtors(int);

    private:
        std::vector <Motor> tabMoteur;
        std::vector <std::string> tabclass;
        int qMotors=0;
        std::string feedBack;
};

#endif // LAMPE_H
