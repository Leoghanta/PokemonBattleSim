#include <iostream>
#include "Wartortle.h"

//Constructor
Wartortle::Wartortle() : Squirtle() {
	std::cout << "======================================================================\n" <<
		"In a sudden swirl of light, " << name << " has evolved to Wartortle\n" <<
		"======================================================================" << std::endl;
	name = "Wartortle";
	strength += 10;
	health += 100;
	max_health += 100;
	experience = 0;
}

Pokemon* Wartortle::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Tail Whap\n   2.Wave Crash\n   3.Heal\n   4.Run Away" << std::endl;
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

void Wartortle::basicAttack(Pokemon& opponent) {
	std::cout << name << " smacks " << opponent.getName() << " with a poweful tail whap!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}

void Wartortle::specialAttack(Pokemon& opponent) {
	std::cout << "From out of nowhere, a large wave engulfs "<< name << std::endl;
	std::cout << name << " sending them flying backwards" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength+30));
}
