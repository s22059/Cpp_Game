
#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H
#include <string>
#include "action.h"
#include <iostream>
using namespace std;
class player
{
public:
    player(string);
    void setName(std::string);
    string getName();
private:
    string playerName;



};




#endif //UNTITLED4_PLAYER_H