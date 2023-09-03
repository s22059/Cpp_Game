//
// Created by deku on 15.06.2022.
//
#include <string>
#ifndef UNTITLED2_POKEMON_H
#define UNTITLED2_POKEMON_H
using namespace std;

class Pokemon {
public:
    Pokemon(string,int,int);
    void setName(std::string);
    void setLevel(int);
    void setEXP(double);
    void setHP(double);
    void setMaxHP();
    void setStrength();
    string getName();
    int getLevel();
    double getHP();
    double getMaxHP();
    int getStrength();
    int getEXP();
    void setEXP(int);
    int getEXPReq();
    void setEXPReq();
    void setType();
    string getTypeinfo();
    string getType();
    Pokemon levelUP(Pokemon);
    void pokeStat() {
        cout<<"Name: "<<pokeName<<endl;
        cout<<"Type: "<<getType()<<endl;
        cout<<"Level: "<<pokeLevel<<endl;
        cout<<"HP: "<<pokeHP<<endl;
        cout<<"EXP: "<<EXP<<"\n"<<endl;
    }
private:
    string pokeName;
    string type;
    int pokeLevel;
    double pokeHP;
    double pokeMaxHP;
    int pokeStrength;
    int EXP;
    int EXPReq;
};


#endif //UNTITLED2_POKEMON_H
