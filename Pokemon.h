#pragma once
#include <iostream>

/*
 POKEMON CLASS 
*/

class Pokemon {
private:
    std::string name;
    std::string type;
    int health;
    int strength;
    int max_health;

public:

    //Constructor
    Pokemon(std::string n, std::string t, int h, int s);

    //Methods
    void actionMenu(Pokemon& opponent);
    void basicAttack(Pokemon& opponent);
    void heal(int amount);
    bool runAway();
    void takeDamage(int damage);
    int getHealth();
};