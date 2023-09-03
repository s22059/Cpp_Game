#ifndef UNTITLED4_ACTION_H
#define UNTITLED4_ACTION_H
#include <string>
using namespace std;
class action {


public:
    action(string,int,int); // name,lvl,special power,difficulty
    void setName(string);
    void setLevel(int);
    void setStrength();
    void setHP(double);
    void setMaxHP();
    void setDifficulty(int);
    string getName();
    int getLevel();
    int getStrength();
    double getHP();
    double getMaxHP();
    int getDifficulty();
    int getEXP();
    void setEXP();
    void setType();
    string getType();
private:
    string mobName;
    string evilType;
    int mobLevel;
    int mobStrength;
    double mobHealth_point;
    double mobMaxHealth_point;
    int mobDifficulty;
    int EXP;

};




#endif //UNTITLED4_ACTION_H