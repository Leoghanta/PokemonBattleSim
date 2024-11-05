/* SQUIRTLE
   Method Definitions
*/
#include <iostream>
#include "Squirtle.h"

//Constructor
Squirtle::Squirtle() : Pokemon("Squirtle", "Water", 100, 25) {};

void Squirtle::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Bubble Beam\n   2.Heal\n   3.Run Away" << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		basicAttack(opponent);
	}
	else if (choice == 2) {
		heal(20);
	}
	else if (choice == 3) {
		if (runAway()) {
			health = 0; //end the battle using health=0 for now.
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
}

void Squirtle::basicAttack(Pokemon& opponent) {
	std::cout << name << " blasts " << opponent.getName() << " with a beam of bubbles!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}