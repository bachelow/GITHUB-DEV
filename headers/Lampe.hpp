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
        static void find_onechar_and_remove(std::string&,char);
        static void find_allchar_and_remove(std::string&,char);
        static std::string until_find_charac(std::string&,char,bool);

    private:
        std::vector <Motor> tabMoteur;
        int qMotors;
        std::string feedBack;
};

#endif // LAMPE_H
