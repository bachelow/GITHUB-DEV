#include <iostream>
#include "../headers/Motor.hpp"
#include <string>
#include "../headers/Lampe.hpp"
#include <vector>

using namespace std;

int main()
{
    Motor m1(SERVOS,RIGHT,0,0);
    Lampe l1;
    int i(0);
    char cc(' ');
    std::string text = "{'Motor':{'m1':{'angle': 90,'speed':40,'sens':'LEFT','type':'STEPPERS},'m2':{'angle': 40,'speed':30,'sens':'LEFT','type':'SERVOS'}}}";
    std::string txt = "coucou : c{a va?";
    //l1.parseJson(text);
    Lampe::find_acc(i,cc,txt);
    cout<< cc<<endl;
    cout << i << endl;
    std::string ll = Lampe::until_find_charac(txt,'{',1);
    cout<< ll << endl;
    cout << txt << endl;
    txt = "2013";
    return 0;
}
