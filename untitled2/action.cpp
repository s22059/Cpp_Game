#include <ctime>
#include "action.h"
#include <string>
action::action(std::string name,int lvl,int difficulty)
{
    setName(name);
    setLevel(lvl);
    setDifficulty(difficulty);
    setStrength();
    setType();
    setMaxHP();
    setHP(mobMaxHealth_point);
    setEXP();
}

void action::setName(std::string name)
{
    mobName = name ;
}

void action::setLevel(int level)
{
    mobLevel = level;
}


void action::setDifficulty(int difficulty)
{
    mobDifficulty = difficulty;
}

void action::setStrength()
{
    mobStrength = (3 *( getLevel())+((getDifficulty()*getLevel())*5));
}

void action::setHP(double health)
{
    mobHealth_point = health;
}
void action::setMaxHP()
{
    mobMaxHealth_point = (15 *(getDifficulty() + getLevel()));
}
std::string action::getName()
{
    return mobName;
}

int action::getLevel()
{
    return mobLevel;
}
int action::getDifficulty()
{
    return mobDifficulty;
}
int action::getStrength()
{
    return mobStrength;
}
double action::getHP()
{
    return mobHealth_point;
}
double action::getMaxHP()
{
    return mobMaxHealth_point;
}

int action::getEXP()
{
    return EXP;
}

void action::setEXP()
{
    EXP = (getLevel() * 35);
}
void action::setType() {
    srand(time(0));
    int a = rand() % (6 - 1 + 1 ) + 1;
    switch (a) {
        case 1:
            evilType = "Water";
            break;
        case 2:
            evilType = "Earth";
            break;
        case 3:
            evilType = "Air";
            break;
        case 4:
            evilType = "Fire";
            break;
        case 5:
            evilType = "Ice";
            break;
        case 6:
            evilType = "Steel";
            break;
    }
}
string action::getType() {
    if (evilType=="Water"){
        return "Water";
    }
    else if(evilType=="Earth"){
        return "Earth";
    }
    else if(evilType=="Air"){
        return "Air";
    }
    else if(evilType=="Fire"){
        return "Fire";
    }
    else if(evilType=="Ice"){
        return "Ice";
    }
    else if(evilType=="Steel"){
        return "Steel";
    }
}