
#include <iostream>
#include "Raichu.h"

//Constructor
Raichu::Raichu() : Pikachu() {
	std::cout << "======================================================================\n" << 
		         "In a sudden swirl of light, " << name << " has evolved to Raichu!\n" << 
		         "======================================================================" << std::endl;
	name = "Raichu";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Raichu::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Thunder Shock\n   2.Lightning Strike\n   3.Heal\n   4.Run Away" << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		basicAttack(opponent);
	}
	else if (choice == 2) {
		specialAttack(opponent);
	}
	else if (choice == 3) {
		heal(20);
	}
	else if (choice == 4) {
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Raichu::basicAttack(Pokemon& opponent) {
	std::cout << name << " zapps " << opponent.getName() << " with Thunder Shock!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Raichu::specialAttack(Pokemon& opponent) {
	std::cout << "Thunderbolt and lightning, very, very frightnening me!" << std::endl;
	std::cout << name << " was hit by a lightning bolt.\n Any way the wind blows..." << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}