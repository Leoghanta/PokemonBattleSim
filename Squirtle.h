#pragma once
#include <iostream>
#include "Pokemon.h"
 
class Squirtle : public Pokemon {

public:
	Squirtle();

	void actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};