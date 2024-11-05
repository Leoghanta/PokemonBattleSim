#pragma once
#include <iostream>
#include "Pokemon.h"

class Pikachu : public Pokemon {

public:
	Pikachu();

	void actionMenu(Pokemon& opponent) override;
	void basicAttack(Pokemon& opponent) override;

};