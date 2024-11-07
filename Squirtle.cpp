/* SQUIRTLE
   Method Definitions
*/
#include <iostream>
#include "Squirtle.h"
#include "Wartortle.h"
  
//Constructor
Squirtle::Squirtle() : Pokemon("Squirtle", "Water", 100, 25) {};

Pokemon* Squirtle::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Bubble Beam\n   2.Heal\n   3.Run Away";
	if (experience > 50) {
		std::cout << "\n   4.Evolve";
	}
	std::cout << std::endl;
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
	else if (choice == 4) {
		if (experience < 50) {
			std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
		}
		else {
			return new Wartortle();
		}
	}
	else {
		std::cout << name << " looks at you funny and shrugs. What does " << choice << " mean?" << std::endl;
	}
	return this;
}

void Squirtle::basicAttack(Pokemon& opponent) {
	std::cout << name << " blasts " << opponent.getName() << " with a beam of bubbles!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}