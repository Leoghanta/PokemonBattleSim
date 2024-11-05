/* CHARMANDER 
   Method Definitions 
*/
#include <iostream>
#include "Charmander.h"

//Constructor
Charmander::Charmander() : Pokemon("Charmander", "Fire", 100, 25) {};

void Charmander::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Flame Thrower\n   2.Heal\n   3.Run Away" << std::endl;
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

void Charmander::basicAttack(Pokemon& opponent) {
	std::cout << name << " burns " << opponent.getName() << " with Flame Thrower!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}