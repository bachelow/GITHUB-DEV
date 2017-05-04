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
    while(text.at(n) != charac){
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
            break;
        }
    }
    return b;
}

void Lampe::getvalue(std::string txt,Moteur_t& type, Direct_t& direction, int& speed, float& angle){
    std::string buffer;
    buffer = until_find_charac(txt,',',1);
    find_allchar_and_remove(buffer,'\'');
    find_allchar_and_remove(buffer,' ');
    if("angle" == buffer){

    }
}


void Lampe::maj(std::vector <Motor> tabmot,int i, Moteur_t type, Direct_t direction, int speed, float angle){
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
    float angle;
    int speed;
    Moteur_t type;
    Direct_t sens;
    while (avancement != text.length()){
        if (the_one == '{'){
            cptaco++;
            find_acc(i,the_one,text2);
            buf = until_find_charac(text2,the_one, 1);
            avancement = text.length() -text2.length();
            find_allchar_and_remove(buf,'\'');
            find_allchar_and_remove(buf,':');
            if (cptaco == 1){
                this->tabclass.push_back(buf);
            }
            else if (cptaco == 2){
                if (find_vector(this->tabMoteur,buf,posMot)){
                    Lampe::find_onechar_and_remove(text2,'{');
                    buf = until_find_charac(text2,'}',1);
                    avancement = text.length() -text2.length();



                }

            }
        }
    }
}