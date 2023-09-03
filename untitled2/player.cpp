
#include "player.h"
#include <string>
player::player(string name)
{
    setName(name);
}

void player::setName(std::string name)
{
    playerName = name;
}

string player::getName()
{
    return playerName;
}




