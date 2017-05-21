#include "Lampe.h"
#include <Arduino.h>
#include "Motor.h"

using namespace std;

Lampe::Lampe()
{
    //ctor
}

Lampe::~Lampe()
{
    //dtor
}

//VECTOR

//Vector
Motor* Lampe::push_backm(int n, Motor ff, Motor tbf[]){
    Motor *tbff = new Motor[n+1];
    for(int k=0; k<n; k++){
        tbff[k] = tbf[k];
    }
    tbff[n] = ff;
    return tbff;

 }

 String* Lampe::push_backc(int n, String ff, String tbf[]){
    String *tbff = new String[n+1];
    for(int k=0; k<n; k++){
        tbff[k] = tbf[k];
    }
    tbff[n] = ff;
    return tbff;

 }







//set and get

Motor* Lampe::gettabMoteur(){
    return this->tabMoteur;
}

String* Lampe::gettabclass(){
   return this->tabclass;
}

String Lampe::getfeedBack(){
    return this->feedBack;
}

int Lampe::getqMotors(){
    return qMotors;
}

void Lampe::settabMoteur(Motor tbm[] ){
    this->tabMoteur = tbm;
}

void Lampe::settabclass(String tbc[]){
    this->tabclass = tbc;
}

void Lampe::setfeedback(String fB){
    this->feedBack = fB;
}

void Lampe::setqMOtors(int qM){
    this->qMotors = qM;
}



//ParseJson functions

void Lampe::find_onechar_and_remove(String& text, char charac){
    for( unsigned int n=0; n< text.length(); n++){
        if(text.charAt(n) == charac){
            text.remove(n,1);
            n = text.length();
        }
    }
}

void Lampe::find_acc(int& i,char& cc, String& text){
    for(unsigned int n=0; n<text.length();n++){
        if((text.charAt(n) == '{') || (text.charAt(n) =='}')){
            cc = text.charAt(n);
            i = n;
            break;
        }
    }
}

void Lampe::find_allchar_and_remove(String& text, char charac){
    for( unsigned int n=0; n< text.length(); n++){
        if(text.charAt(n) == charac){
            text.remove(n,1);
            n--;
        }
    }
}

String Lampe::until_find_charac(String& text, char charac, bool b){
    int n(0);
    int len = text.length();
    while(text.charAt(n) != charac){
        if(len-1 == n){
            b=0;
            break;
        }
        n++;
    }
    char sol[n+1];
    text.toCharArray(sol,n+1); //sol = buffer, n taille a copier, 0 le debut
    //String str = String(sol);

    if (b==1){
        text.remove(0,n);
    }
    return sol;
}

bool Lampe::find_vector(int tablength, Motor* tabmot, String& m, int& i){
    bool b(0);
    for( unsigned int n=0; n< tablength; n++){
        if(m == tabmot[n].getName()){
            b = 1;
            i = n;
            break;
        }
    }
    return b;
}

void Lampe::getvalue(String& txt,Moteur_t& type, Direct_t& direction, int& speed, float& angle){
    String buffer;
    String buff2;
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
            angle = buffer.toFloat();
        }
        else if(buff2 == "speed"){
            Lampe::find_onechar_and_remove(buffer,':');
            speed = buffer.toInt();
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


void Lampe::maj(Motor* tabmot,int i, Moteur_t type, Direct_t direction, int speed, float angle){
    tabmot[i].setAngle(angle);
    tabmot[i].setDir(direction);
    tabmot[i].setSpeed(speed);
    tabmot[i].setType(type);
}

void Lampe::parseJson(String& text, int sizeoftab){
    String text2 = text;
    int cptaco = 0;
    int i = 0;
    int posMot;
    unsigned int avancement = 0;
    char aco('{');
    char acf('}');
    char the_one('{');
    String buf;
    String buff;
    float angle;
    int speed;
    Moteur_t type;
    Direct_t direction;
    int tabmotlength(1);
    int tabclasslength(0);
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
                this->tabclass = push_backc(tabclasslength,buf,this->tabclass);
                tabclasslength++;

            }
            else if (cptaco == 2){
                if(text2.charAt(0) == '{'){
                find_onechar_and_remove(text2,'{');
                }
                buff = until_find_charac(text2,the_one, 1);
                avancement = text.length() -text2.length();
                find_allchar_and_remove(buff,'\'');
                find_allchar_and_remove(buff,':');
                find_allchar_and_remove(buff,' ');
                if (find_vector(tabmotlength,this->tabMoteur,buff,posMot)){
                    find_onechar_and_remove(text2,'{');
                    //Serial.println("###################");



                    int n(0);
                    int len = text2.length();
                    bool b;
                    b =1;
                    while(text2.charAt(n) != '}'){
                        if(len-1 == n){
                            b=0;
                            break;
                        }
                        n++;
                    }
                    char sol[n+1];
                    text2.toCharArray(sol,n+1); //sol = buffer, n taille a copier, 0 le debut
                    if (b==1){
                        text2.remove(0,n);
                    }
                    buf = sol;



                    //Serial.println("###################"); 
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
                    this->tabMoteur = push_backm(tabmotlength,m1,this->tabMoteur);
                    tabmotlength++;
                    //break;
                }

            }
        }

        else{
            cptaco--;
            find_onechar_and_remove(text2,'}');
            find_acc(i,the_one,text2);
            if(text2.charAt(0) == ','){
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

void Lampe::affiche(){
    Serial.println(this->gettabMoteur()[0].getName());Serial.println(this->gettabMoteur()[0].getSpeed());Serial.println(this->gettabMoteur()[0].getAngle());Serial.println(this->gettabMoteur()[0].getType());Serial.println(this->gettabMoteur()[0].getDir());

    Serial.println("###########");
    Serial.println(this->gettabMoteur()[1].getName());Serial.println(this->gettabMoteur()[1].getSpeed());Serial.println(this->gettabMoteur()[1].getAngle());Serial.println(this->gettabMoteur()[1].getType());Serial.println(this->gettabMoteur()[1].getDir());
    Serial.println("###########");
    Serial.println(this->gettabMoteur()[2].getName());Serial.println(this->gettabMoteur()[2].getSpeed());Serial.println(this->gettabMoteur()[2].getAngle());Serial.println(this->gettabMoteur()[2].getType());Serial.println(this->gettabMoteur()[2].getDir());
    Serial.println("###########");
    Serial.println(this->gettabMoteur()[3].getName());Serial.println(this->gettabMoteur()[3].getSpeed());Serial.println(this->gettabMoteur()[3].getAngle());Serial.println(this->gettabMoteur()[3].getType());Serial.println(this->gettabMoteur()[3].getDir());

}