#pragma once
#include <iostream>

/*
 POKEMON CLASS 
*/

class Pokemon {
protected:
    std::string name;
    std::string type;
    int health;
    int strength;
    int max_health;

public:

    //Constructor
    Pokemon(std::string n, std::string t, int h, int s);

    //Methods
    virtual void actionMenu(Pokemon& opponent);
    virtual void basicAttack(Pokemon& opponent);
    int calculateDamage(Pokemon& opponent, int damage);
    void heal(int amount);
    bool runAway();
    void takeDamage(int damage);
    int getHealth();
    std::string getName();
};