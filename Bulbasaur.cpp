/* BULBASAUR
   Method Definitions
*/
#include <iostream>
#include "Bulbasaur.h"
 
//Constructor
Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", "Grass", 100, 25) {};

void Bulbasaur::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Body Slam\n   2.Heal\n   3.Run Away" << std::endl;
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

void Bulbasaur::basicAttack(Pokemon& opponent) {
	std::cout << name << " Runs towards " << opponent.getName() << " slamming them with a Body Slam!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}