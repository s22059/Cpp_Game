//
// Created by deku on 15.06.2022.
//
#include <string>
#include <iostream>
#include <ctime>
#include "Pokemon.h"
using namespace std;
Pokemon::Pokemon(string pokeName,int level=1,int exp=0) {
    setName(pokeName);
    setLevel(level);
    setEXP(exp);
    setMaxHP();
    setHP(pokeMaxHP);
    setStrength();
    setType();
    setEXPReq();
}

void Pokemon::setName(string name)
{
    pokeName = name;
}
void Pokemon::setLevel(int level)
{
    pokeLevel = level;
}
void Pokemon::setHP(double health)
{
   pokeHP = health;
}
void Pokemon::setMaxHP()
{
    pokeMaxHP = (100 * getLevel());
}
void Pokemon::setStrength()
{
    pokeStrength = (30 * getLevel());
}

string Pokemon::getName()
{
    return pokeName;
}


int Pokemon::getLevel()
{
    return pokeLevel;
}
double Pokemon::getHP()
{
    return pokeHP;
}
double Pokemon::getMaxHP()
{
    return pokeMaxHP;
}
int Pokemon::getStrength()
{
    return pokeStrength;
}

int Pokemon::getEXP()
{
    return EXP;
}
void Pokemon::setEXP(int tmpExp)
{
    EXP = tmpExp;
}
int Pokemon::getEXPReq()
{
    return EXPReq;
}
void Pokemon::setEXPReq()
{
    EXPReq = 70+((getLevel()*getLevel())*35);
}
void Pokemon::setType() {
    srand(time(0));
    int a = rand() % (6 - 1 + 1 ) + 1;
    switch (a) {
        case 1:
            type = "Water";
            break;
        case 2:
            type = "Earth";
            break;
        case 3:
            type = "Air";
            break;
        case 4:
            type = "Fire";
            break;
        case 5:
            type = "Ice";
            break;
        case 6:
            type = "Steel";
            break;
    }
}
string Pokemon::getTypeinfo() {
    if (type=="Water"){
        cout<<"Water: \n"
              "Strong against Earth and Fire \n"
              "Weak against Water"<<endl;
    }
    else if(type=="Earth"){
        cout<<"Earth: \n"
              "Strong against Fire, Ice, Steel \n"
              "Weak against Air"<<endl;
    }
    else if(type=="Air"){
        cout<<"Air: \n"
              "Strong against Ice \n"
              "Weak against Steel and Earth"<<endl;
    }
    else if(type=="Fire"){
        cout<<"Fire: \n"
              "Strong against Ice and Steel \n"
              "Weak against Water and Earth"<<endl;
    }
    else if(type=="Ice"){
        cout<<"Ice: \n"
              "Strong against Earth \n"
              "Weak against Water, Fire and Ice"<<endl;
    }
    else if(type=="Steel"){
        cout<<"Steel: \n"
              "Strong against Water and Air \n"
              "Weak against Fire and Steel"<<endl;
    }
}

string Pokemon::getType() {
    if (type=="Water"){
        return "Water";
    }
    else if(type=="Earth"){
        return "Earth";
    }
    else if(type=="Air"){
        return "Air";
    }
    else if(type=="Fire"){
        return "Fire";
    }
    else if(type=="Ice"){
        return "Ice";
    }
    else if(type=="Steel"){
        return "Steel";
    }
}


Pokemon Pokemon::levelUP(Pokemon account) {
    account.setLevel(account.getLevel()+1);
    account.setEXPReq();
    account.setMaxHP();
    account.setHP(account.getMaxHP());
    cout << "Congrats ! you leveled up: " << account.getLevel() << "!\n";
    return account;
}
