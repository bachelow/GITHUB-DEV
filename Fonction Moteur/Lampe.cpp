#include "../headers/Lampe.hpp"
#include <vector>
#include <iostream>
#include "../headers/Motor.hpp"

using namespace std;

Lampe::Lampe()
{
    //ctor
}

Lampe::~Lampe()
{
    //dtor
}

//set and get

std::vector <Motor> Lampe::gettabMoteur(){
    return this->tabMoteur;
}

std::vector <std::string> Lampe::gettabclass(){
    return this->tabclass;
}

std::string Lampe::getfeedBack(){
    return this->feedBack;
}

int Lampe::getqMotors(){
    return qMotors;
}

void Lampe::settabMoteur(std::vector <Motor> tbm ){
    this->tabMoteur = tbm;
}

void Lampe::settabclass(std::vector <std::string> tbc){
    this->tabclass = tbc;
}

void Lampe::setfeedback(std::string fB){
    this->feedBack = fB;
}

void Lampe::setqMOtors(int qM){
    this->qMotors = qM;
}



//ParseJson functions

void Lampe::find_onechar_and_remove(std::string& text, char charac){
    for( unsigned int n=0; n< text.length(); n++){
        if(text.at(n) == charac){
            text.erase(text.begin() + n);
            n = text.length();
        }
    }
}

void Lampe::find_acc(int& i,char& cc, std::string text){
    for(unsigned int n=0; n<text.length();n++){
        if((text.at(n) == '{') || (text.at(n) =='}')){
            cc = text.at(n);
            i = n;
            break;
        }
    }
}

void Lampe::find_allchar_and_remove(std::string& text, char charac){
    for( unsigned int n=0; n< text.length(); n++){
        if(text.at(n) == charac){
            text.erase(text.begin() + n);
        }
    }
}

std::string Lampe::until_find_charac(std::string& text, char charac, bool b){
    int n(0);
    int len = text.length();
    while(text.at(n) != charac){
        if(len-1 == n){
            b=0;
            break;
        }
        n++;
    }
    char sol[n];
    std::size_t length = text.copy(sol,n,0); //sol = buffer, n taille a copier, 0 le debut
    sol[length] = '\0';
    string str(sol);

    if (b==1){
        text.erase(0,n);
    }
    return str;
}

bool Lampe::find_vector(std::vector <Motor> tabmot, std::string m, int& i){
    bool b;
    unsigned int sizee = tabmot.size();
    for( unsigned int n=0; n< sizee; n++){
        if(m == tabmot[n].getName()){
            b = 1;
            i = n;
            break;
        }
    }
    return b;
}

void Lampe::getvalue(std::string txt,Moteur_t& type, Direct_t& direction, int& speed, float& angle){
    std::string buffer;
    std::string buff2;
    int txtbuf(0);
    while(txt.length() != 0){
        txtbuf = txt.length();
        buffer = Lampe::until_find_charac(txt, ',',1);
        Lampe::find_onechar_and_remove(txt,',');
        Lampe::find_allchar_and_remove(buffer,'\'');
        Lampe::find_allchar_and_remove(buffer, ' ');
        //cout << buffer << endl << txt << endl;
        buff2 = Lampe::until_find_charac(buffer,':',1);
        //on fait les bails
        if(buff2 == "angle"){
            Lampe::find_onechar_and_remove(buffer,':');
            angle = std::stof(buffer);
        }
        else if(buff2 == "speed"){
            Lampe::find_onechar_and_remove(buffer,':');
            speed = std::stoi(buffer);
        }
        else if(buff2 =="direction"){
            Lampe::find_onechar_and_remove(buffer,':');
            if(buffer == "LEFT")
                direction = LEFT;
            else{
                direction = RIGHT;
            }
        }
        else if(buff2 =="type"){
            Lampe::find_onechar_and_remove(buffer,':');
            if(buffer == "STEPPERS"){
                type = STEPPERS;
            }
            else{
                type = SERVOS;
            }
        }
        if (txt.length() == txtbuf){break;}
    }
}


void Lampe::maj(std::vector <Motor>& tabmot,int i, Moteur_t type, Direct_t direction, int speed, float angle){
    tabmot[i].setAngle(angle);
    tabmot[i].setDir(direction);
    tabmot[i].setSpeed(speed);
    tabmot[i].setType(type);
}

void Lampe::parseJson(std::string text){
    std::string text2 = text;
    int cptaco = 0;
    int i = 0;
    int posMot;
    unsigned int avancement = 0;
    char aco('{');
    char acf('}');
    char the_one('{');
    std::string buf;
    std::string buff;
    float angle;
    int speed;
    Moteur_t type;
    Direct_t direction;
    while (avancement != text.length()){
        find_acc(i,the_one,text2);
        if (the_one == '{'){
            cptaco++;
            if (cptaco == 1){
                find_onechar_and_remove(text2,'{');
                buf = until_find_charac(text2,the_one, 1);
                avancement = text.length() -text2.length();
                find_allchar_and_remove(buf,'\'');
                find_allchar_and_remove(buf,':');
                this->tabclass.push_back(buf);

            }
            else if (cptaco == 2){
                if(text2.at(0) == '{'){
                find_onechar_and_remove(text2,'{');
                }
                buff = until_find_charac(text2,the_one, 1);
                avancement = text.length() -text2.length();
                find_allchar_and_remove(buff,'\'');
                find_allchar_and_remove(buff,':');
                find_allchar_and_remove(buff,' ');
                if (find_vector(this->tabMoteur,buff,posMot)){
                    find_onechar_and_remove(text2,'{');
                    buf = until_find_charac(text2,'}',1);
                    avancement = text.length() -text2.length();
                    getvalue(buf,type,direction,speed,angle);
                    maj(this->tabMoteur,posMot,type,direction,speed,angle);
                    //break;
                }
                else{
                    find_onechar_and_remove(text2,'{');
                    buf = until_find_charac(text2,'}',1);
                    avancement = text.length() -text2.length();
                    getvalue(buf,type,direction,speed,angle);
                    Motor m1(type,direction,speed,angle,buff);
                    this->tabMoteur.push_back(m1);
                    //break;
                }

            }
        }

        else{
            cptaco--;
            find_onechar_and_remove(text2,'}');
            find_acc(i,the_one,text2);
            if(text2.at(0) == ','){
                find_onechar_and_remove(text2,',');
            }
            while('}' == the_one){
                cptaco--;
                if((the_one == '{')||(cptaco == -1)){
                    avancement = text.length();
                    break;
                }
                until_find_charac(text2,'}',1);
                find_onechar_and_remove(text2,'}');
                find_acc(i,the_one,text2);
            }
        }


    }
}
