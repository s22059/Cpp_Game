#include "action.h"
#include "player.h"
#include "Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
Pokemon battle(Pokemon poke);
Pokemon calcEXP(Pokemon poke,action monster);
Pokemon levelUp(Pokemon poke);
void death();

int main()
{
    string PlayerName;
    string PokeName;
    int choice;
    cout << "Welcome, please enter your name\n";
    cin >> PlayerName;
    cout << "You must excited about your new adventure.\n"
            "But first you should find one Pokemon\n"
            "If you ask 'what is Pokemon?'\n"
            "The answer is simple. After WW3 we lost many of adults.\n"
            "However we survived I mean the young people like you and\n"
            " elder people like me. After biohazard disappeared. We started to go out\n"
            " of the shelters. This is the first time we found these 'Pokemons'\n"
            "No one knows where they came from but they are friendly.\n";
    cout << "\n After half an hour you heard something from bushes\n";
    cout << "You found Pokemon! \n"
            "How will you call it? \n";
    cin >> PokeName;
    Pokemon poke(PokeName,1,0);
    player account(PlayerName);
    cout <<"\nHello "<<account.getName() <<" and you too, little "<<poke.getName()<<"\nlets start the adventure:)\n";
    while (1)
    {
        cout <<"Type\n"
               "1-to walk around\n"
               "2-to check you pokemon's stats\n"
               "3-to info about type\n"
               "4-to help\n";
        cin >> choice;
        if (choice==1)
        {
            srand(time(NULL));
            if (rand() %3 == choice-1){
                poke = battle(poke);
            }
        }
        else if (choice==2){
            poke.pokeStat();
        }
        else if (choice==3){
            poke.getTypeinfo();
            cout<<"\n";
        }
        else if (choice==4){
            cout<<"All the instructions are inside of the game\n"
                  "if you want to ask more questions please\n"
                  "mail to this address: candasztrk@gmail.com\n";
        }
        else{
            cout << "\ntype something between 1-3\n\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}




Pokemon battle(Pokemon poke)
{
    string option;
    string monsters[2][8] = {{"Gazeceon","Peliton","Spidig","Elepharing","Doomdine","Hypeking","Gothamander","Huntoon"},
                             {"Apricode","Rabbyte","Fieron","Quilzelle","Bisong","Jaguava","Golehawk","Leopia"}};

    srand(time(NULL));
    int ranM = (rand() % 8); //random monster
    int ranD = (rand() % 2)+1; //random diff
    action monster(monsters[poke.getLevel()-1][ranM],poke.getLevel(),ranD);
    cout <<"Enemy appeared. Unknown person: Alright "<< monster.getName() <<" get ready for action." << "\n";

    do
    {
        string a=monster.getType();
        cout << "\n\n\n -------------------------------------\nHP:"<< poke.getHP() << "                                         "<< monster.getName()<<"HP:"<<monster.getHP()<<" difficulty:"<<monster.getDifficulty() << "\n";
        cout << " Type A for attack and F for flee\ntip:if the hp is low you should flee." << "\n";
        cin >> option;
        srand(time(NULL));
        if (option == "F" || option == "f")
        {
            if ((rand() % 2) == 1){
                cout << "flee successful" << "\n";
                monster.setHP(0);
            }
            else{
                cout << "You couldn't escape from it. It attacked you from your back (your pokemon lost 5 hp)\n";
                poke.setHP(poke.getHP()-5);
                option ="A";
            }
        }
        if (option == "A" || option == "a")
        {
            int attack =rand()%(poke.getStrength());
            srand(time(NULL));
            int mobAttack = rand()%(monster.getStrength());
            string mobType = monster.getType();
            string pokeType = poke.getType();
            //poke WATER ATTACK
            if (pokeType=="Water"){
                if(mobType=="Water"){
                    cout <<poke.getName()<<" attacked with a water gun:"<< attack*0.7<<" damage. Not very Effective."<<endl;
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Earth"||mobType=="Fire"){
                    cout <<poke.getName()<<" attacked with a water gun:"<<attack*1.7 <<" damage. Very effective!" <<endl;
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if (mobType=="Air"||mobType=="Ice"||mobType=="Steel") {
                    cout << poke.getName() << " attacked with a Water pulse:" << attack << " damage."
                         << endl;
                    monster.setHP(monster.getHP() - attack);
                }
            }
            //poke EARTH ATTACK
            else if (pokeType=="Earth"){
                if(mobType=="Air"){
                    cout <<poke.getName()<<" attacked with a Razor leaf:"  << attack*0.7 << " damage. Not very Effective."<<endl;
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Fire"||mobType=="Ice"||mobType=="Steel"){
                    cout <<poke.getName()<<" attacked with a Razor leaf:"  << attack*1.7 << " damage. Very effective!"<<endl;
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if (mobType=="Water"||mobType=="Earth"){
                    cout <<poke.getName()<<" attacked with a Razor leaf:"  << attack << " damage."<<endl;}
                    monster.setHP(monster.getHP()-attack);
            }
            //poke AIR ATTACK
            else if (pokeType=="Air"){
                if(mobType=="Earth"||mobType=="Steel"){
                    cout <<poke.getName()<<" attacked with a Air slash:"  << attack*0.7 << " damage. Not very Effective."<<endl;
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Ice"){
                    cout <<poke.getName()<<" attacked with a Air slash:"  << attack*1.7 << " damage. Very effective!"<<endl;
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if (mobType=="Water"||mobType=="Air"||mobType=="Fire"){
                    cout <<poke.getName()<<" attacked with a Air slash:"  << attack << " damage."<<endl;}
                    monster.setHP(monster.getHP()-attack);
            }
            //poke FIRE ATTACK
            else if (pokeType=="Fire"){
                if(mobType=="Water"||mobType=="Earth"){
                    cout <<poke.getName()<<" attacked with a Flame thrower:"  << attack*0.7 << " damage. Not very Effective.";
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Ice"||mobType=="Steel"){
                    cout <<poke.getName()<<" attacked with a Flame thrower:"  << attack*1.7 << " damage. Very effective!";
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if(mobType=="Fire"||mobType=="Fire"||mobType=="Fire"){
                    cout <<poke.getName()<<" attacked with a Flame thrower:"  << attack << " damage.";}
                    monster.setHP(monster.getHP()-attack);
            }
            //poke ICE ATTACK
            else if (pokeType=="Ice"){
                if(mobType=="Water"||mobType=="Fire"||mobType=="Ice"){
                    cout <<poke.getName()<<" attacked with a Ice ball:"  << attack*0.7 << " damage. Not very Effective."<<endl;
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Earth"){
                    cout <<poke.getName()<<" attacked with a Ice ball:"  << attack*1.7 << " damage. Very effective!"<<endl;
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if(mobType=="Air"||mobType=="Steel"){
                    cout <<poke.getName()<<" attacked with a Ice ball:"  << attack << " damage."<<endl;}
                    monster.setHP(monster.getHP()-attack);
            }
            //poke STEEL ATTACK
            else if (pokeType=="Steel"){
                if(mobType=="Fire"||mobType=="Steel"){
                    cout <<poke.getName()<<" attacked with a Iron tail:"  << attack*0.7 << " damage. Not very Effective."<<endl;
                    monster.setHP(monster.getHP()-attack*0.7);
                }
                else if(mobType=="Water"||mobType=="Air"){
                    cout <<poke.getName()<<" attacked with a Iron tail:"  << attack*1.7 << " damage. Very effective!"<<endl;
                    monster.setHP(monster.getHP()-attack*1.7);
                }
                else if(mobType=="Earth"||mobType=="Ice"){
                    cout <<poke.getName()<<" attacked with a Iron tail:"  << attack << " damage."<<endl;}
                    monster.setHP(monster.getHP()-attack);
            }

            //monster WATER ATTACK
            if (mobType=="Water"){
                if(pokeType=="Water"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a water splash:" << mobAttack*0.6 << " damage\n Not very Effective."<<endl;
                }
                else if(pokeType=="Earth"||pokeType=="Fire"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a water splash:" << mobAttack*1.6 << " damage\n Very effective!"<<endl;
                }
                else if(pokeType=="Air"||pokeType=="Ice"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a water splash:"  << mobAttack << " damage\n"<<endl;}
            }
            //monster EARTH ATTACK
            else if (mobType=="Earth"){
                if(pokeType=="Air"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a Ivy whip:"  << mobAttack*0.6 << " damage\n Not very Effective."<<endl;
                }
                else if(pokeType=="Fire"||pokeType=="Ice"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a Ivy whip:"  << mobAttack*1.6 << " damage\n Very effective!"<<endl;
                }
                else if(pokeType=="Water"||pokeType=="Earth"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a Ivy whip:"  << mobAttack << " damage\n"<<endl;}
            }
            //monster AIR ATTACK
            else if (mobType=="Air"){
                if(pokeType=="Earth"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a Hurricane:"  << mobAttack*0.6 << " damage\n Not very Effective."<< endl;
                }
                else if(pokeType=="Ice"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a Hurricane:"  << mobAttack*1.6 << " damage\n Very effective!"<< endl;
                }
                else if(pokeType=="Water"||pokeType=="Air"||pokeType=="Fire"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a Hurricane:"  << mobAttack << " damage\n"<< endl;}
            }
            //monster FIRE ATTACK
            else if (mobType=="Fire"){
                if(pokeType=="Water"||pokeType=="Earth"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a Fireball:"  << mobAttack*0.6 << " damage\n Not very Effective."<<endl;
                }
                else if(pokeType=="Ice"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a Fireball:"  << mobAttack*1.6 << " damage\n Very effective!"<<endl;
                }
                else if(pokeType=="Air"||pokeType=="Fire"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a Fireball:"  << mobAttack << " damage\n"<<endl;}
            }
            //monster ICE ATTACK
            else if (mobType=="Ice"){
                if(pokeType=="Water"||pokeType=="Fire"||pokeType=="Ice"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a Ice spear:"  << mobAttack*0.6 << " damage\n Not very Effective."<<endl;
                }
                else if(pokeType=="Earth"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a Ice spear:"  << mobAttack*1.6 << " damage\n Very effective!"<<endl;
                }
                else if(pokeType=="Air"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a Ice spear:"  << mobAttack << " damage\n"<<endl;}
            }
            //monster STEEL ATTACK
            else if (mobType=="Steel"){
                if(pokeType=="Fire"||pokeType=="Steel"){
                    poke.setHP(poke.getHP()-mobAttack*0.6);
                    cout <<monster.getName()<<" attacked with a Bullet punch:"  << mobAttack*0.6 << " damage\n Not very Effective."<<endl;
                }
                else if(pokeType=="Water"||pokeType=="Air"){
                    poke.setHP(poke.getHP()-mobAttack*1.6);
                    cout <<monster.getName()<<" attacked with a Bullet punch:"  << mobAttack*1.6 << " damage\n Very effective!"<<endl;
                }
                else if(pokeType=="Earth"||pokeType=="Ice"){
                    poke.setHP(poke.getHP()-mobAttack);
                    cout <<monster.getName()<<" attacked with a Bullet punch:"  << mobAttack << " damage\n"<<endl;}
            }


        }
    } while (monster.getHP() >0 && poke.getHP() > 0);
    cout << "\n-----------\nHP:"<< monster.getName()<<"HP:"<<monster.getHP() << "    "<< monster.getName()<<"HP:"<<monster.getHP()<<"Type: "<<monster.getType()<<" difficulty:"<<monster.getDifficulty() << "\n";
    if (poke.getHP() <= 0)
    {
        death();
        exit(0);
    }
    poke = calcEXP(poke,monster);
    return poke;
}



void death()
{
    cout << "Your Pokemon died. Game over\n";
}

Pokemon calcEXP(Pokemon poke,action monster)
{
    cout << "----------\ncalculating EXP\n---------\n";

    poke.setEXP(poke.getEXP() + monster.getEXP());
    cout << "EXP: " <<poke.getEXP() << "/" << poke.getEXPReq() << "\n";
    if (poke.getEXP() >= poke.getEXPReq())
    {
        poke.levelUP(poke);
        poke.setEXP(0);
        poke.setHP(poke.getHP()+15);
    }
    return poke;
}



