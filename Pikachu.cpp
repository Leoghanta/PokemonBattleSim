/* PIKACHU CLASS METHODS
*/

#include <iostream>
#include "Pikachu.h"

//Constructor
Pikachu::Pikachu() : Pokemon("Pikachu", "Electric", 100, 25) {};

void Pikachu::actionMenu(Pokemon &opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1.Thunder Shock\n   2.Heal\n   3.Run Away" << std::endl;
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

void Pikachu::basicAttack(Pokemon& opponent) {
	std::cout << name << " zapps " << opponent.getName() << " with Thunder Shock!" << std::endl;
	opponent.takeDamage(calculateDamage(opponent, strength));
}