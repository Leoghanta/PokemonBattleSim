/* GAME CLASS METHODS
 */

#include <iostream>
#include "Game.h"

/// <summary>
/// Start the Simulator by choosing pokemon and battling.
/// </summary>
void Game::start() {
	playerPokemon = SelectPokemon("Choose Your Pokemon");
	opponentPokemon = SelectPokemon("Choose Your Opponent");
	Battle();
}

/// <summary>
/// Select a pokemon and return it.
/// </summary>
/// <param name="prompt">Prompt who the pokemon is for</param>
/// <returns>new Pokemon object</returns>
Pokemon* Game::SelectPokemon(std::string prompt) {
	int choice;
	std::cout << "   1. Pikachu\n   2. Charmander\n   3. Squirtle\n   4. Bulbasaur" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1: return new Pokemon("Pikachu", "Electric", 100, 25);
	case 2: return new Pokemon("Charmander", "Fire", 100, 20);
	case 3: return new Pokemon("Squirtle", "Water", 100, 20);
	case 4: return new Pokemon("Bulbasaur", "Grass", 100, 20);
	default:
		std::cout << "Invalid Choice! You're getting a Jigglypuff!" << std::endl;
		return new Pokemon("JigglyPuff", "Fairy", 10, 1);
	}
}

/// <summary>
/// Run the battle simulator while nobody is dead. Take turns.
/// </summary>
void Game::Battle() {
	while ((playerPokemon->getHealth() > 0) && (opponentPokemon->getHealth() > 0)) {
		std::cout << "Your Turn!" << std::endl;
		playerPokemon->actionMenu(*opponentPokemon);

		if (opponentPokemon->getHealth() > 0) {
			std::cout << "Opponent's Turn!" << std::endl;
			opponentPokemon->actionMenu(*playerPokemon);
		}
	}
	std::cout << "\n\nBATTLE ENDS!" << std::endl;
}

