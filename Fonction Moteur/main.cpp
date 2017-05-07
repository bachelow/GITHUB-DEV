#include <iostream>
#include "../headers/Motor.hpp"
#include <string>
#include "../headers/Lampe.hpp"
#include <vector>


using namespace std;

int main()
{
    Motor m1(SERVOS,RIGHT,0,0,"m2");
    std::vector <Motor> tbm;
    std::vector <std::string> tbc;
    tbm.push_back(m1);
    tbc.push_back("Motor");
    Lampe l1;
    l1.settabMoteur(tbm);
    l1.settabclass(tbc);
    std::string text = "{'Motor':{'m4':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},{'m4':{'angle':9000,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m3':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m2':{'angle': 40,'speed':30,'direction':'LEFT','type':'SERVOS'}}}";
    std::string txt = "coucou : c{a va?";
    txt = "'angle': 90,'speed':40,'direction':'RIGHT','type':'STEPPERS'";
    l1.parseJson(text);
    cout << "["<< l1.gettabMoteur()[0].getName() << "," << l1.gettabMoteur()[0].getAngle() << "," << l1.gettabMoteur()[0].getDir() << ","<< l1.gettabMoteur()[0].getType() << "]" << endl;
    cout << "["<< l1.gettabMoteur()[1].getName() << "," << l1.gettabMoteur()[1].getAngle() << "," << l1.gettabMoteur()[1].getDir() << ","<< l1.gettabMoteur()[1].getType() << "]" << endl;
    cout << "["<< l1.gettabMoteur()[2].getName() << "," << l1.gettabMoteur()[2].getAngle() << "," << l1.gettabMoteur()[2].getDir() << ","<< l1.gettabMoteur()[2].getType() << "]" << endl;
    cout << "["<< l1.gettabMoteur()[3].getName() << "," << l1.gettabMoteur()[3].getAngle() << "," << l1.gettabMoteur()[3].getDir() << ","<< l1.gettabMoteur()[3].getType() << "]" << endl;
    return 0;
}
