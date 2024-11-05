#pragma once
#include <iostream>
#include "Pokemon.h"

class Bulbasaur : public Pokemon {

public:
	Bulbasaur();

	void actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};