/* POKEMON CLASS METHODS
 */

#include <iostream>
#include "Pokemon.h"

//Constructor
Pokemon::Pokemon(std::string n, std::string t, int h, int s) {
	name = n;
	type = t;
	health = h;
	strength = s;
	max_health = health;
	std::cout << name << " clambers to his feet." << std::endl;
}

//Methods

/// <summary>
/// Ask to perform an action for this pokemon. attack, heal, or run.
/// </summary>
/// <param name="opponent">Pokemon opponent</param>
void Pokemon::actionMenu(Pokemon& opponent) {
	int choice;
	std::cout << name << ", select an action" << std::endl;
	std::cout << "   1. Attack\n   2.Heal\n   3.Run Away" << std::endl;
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

/// <summary>
/// This pokemon performs a basic attack on opponent
/// </summary>
/// <param name="opponent">Opposing Pokemon</param>
void Pokemon::basicAttack(Pokemon& opponent) {
	std::cout << name << " attacks " << opponent.name << " with a basic attack " << std::endl;
	opponent.takeDamage(strength);
}

/// <summary>
/// Heal a pokemon by an amount. health can't be greater than max_health.
/// </summary>
/// <param name="amount">amount to heal</param>
void Pokemon::heal(int amount) {
	std::cout << "You heal " << name << "." << std::endl;
	health += amount;
	if (health > max_health){
		health = max_health;
		std::cout << name << " is fully healed!" << std::endl;
	}
}

/// <summary>
/// There's a 25% chance they will successfully flee the fight.
/// </summary>
/// <returns>True if successful, false if not.</returns>
bool Pokemon::runAway() {
	if (rand() % 100 < 25) {
		std::cout << name << " successfully flees from the fight and clambers back into his Pokeball." << std::endl;
		return true;
	}
	else {
		std::cout << name << " couldn't get away!" << std::endl;
	}
	return false;
}


/// <summary>
/// Pokemon takes an amount of damage sapping his health
/// </summary>
/// <param name="damage">amount of damage taken.</param>
void Pokemon::takeDamage(int damage) {
	health -= damage;
	std::cout << name << " takes " << damage << " damage! Health is now " << health << "." << std::endl;
	if (health <= 0) {
		std::cout << name << " has fainted!" << std::endl;
		health = 0;  // Ensure health does not go below zero
	}
}

/// <summary>
/// Getter for pokemon's health.
/// </summary>
/// <returns>Health as integer</returns>
int Pokemon::getHealth() {
	return health;
}