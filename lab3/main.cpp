#include <vector>
#include "player.h"
#include "environment.h"

using namespace lab3;

std::vector<Environment *> initialize(Player& player);

int main() {

	std::string player_name;
	std::cout << "Player name:" << std::endl;
	std::cin >> player_name;

	Player player = Player(player_name, 100, 100);

	std::vector<Environment *> environments = initialize(player);

	while (true) {
		for (int i = 0; i < environments.size(); i++) {
			Environment& env = *environments[i];

			std::vector<Character *> characters = env.getCharacters();

			for (std::vector<Character *>::iterator it=characters.begin();it!=characters.end();){
		  		(*(*it)).action(env);
			}
		}
	}
}

std::vector<Environment *> initialize(Player& player) {
	return std::vector<Environment *>();
}