#include "../headers/Lampe.hpp"

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

void Lampe::parseJson(std::string text){
    std::string text2 = text;
    int cptacou = 0;
    int cptacfe = 0;
    unsigned int avancement = 0;
    char aco('{');
    char acf('}');
    while (avancement != text.length()){

    }
}
