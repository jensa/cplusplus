#include <vector>
#include "character/player.h"
#include "character/troll.h"
#include "object/ring.h"
#include "environment/environment.h"
#include "object/bag.h"

using namespace lab3;

std::vector<Environment *> initialize(Player& player);

int main(){

	Player player = Player("player", 100, 100);

	std::vector<Environment *> environments = initialize(player);

	while (true){
		for (int i = 0; i < environments.size(); i++){
			Environment& env = *environments[i];
			std::vector<std::string> character_names = env.getCharacterNames();
			
			for (int i = 0; i < character_names.size(); i++){
				Character& character = env.getCharacter(character_names[i]);
		  		character.action(env);
			}
		}
	}
}

std::vector<Environment *> initialize(Player& player){
	std::vector<Environment *> environments;

	Environment* upper_right = new Environment("Upper right");
	Environment* upper_left = new Environment("Upper left");
	Environment* lower_right = new Environment("Lower right");
	Environment* lower_left = new Environment("Lower left");

	(*upper_right).set_neighbor("west", upper_left);
	(*upper_right).set_neighbor("south", lower_right);

	(*upper_left).set_neighbor("east", upper_right);
	(*upper_left).set_neighbor("south", lower_left);

	(*lower_right).set_neighbor("west", lower_left);
	(*lower_right).set_neighbor("north", upper_right);

	(*lower_left).set_neighbor("east", lower_right);
	(*lower_left).set_neighbor("north", upper_left);

	(*lower_right).enter(player);

	Troll* troll1 = new Troll("troll1", 10, 10);
	Troll* troll2 = new Troll("troll2", 10, 10);
	Troll* troll3 = new Troll("troll3", 10, 10);
	Troll* troll4 = new Troll("troll4", 10, 10);

	(*lower_right).enter(*troll1);
	(*lower_left).enter(*troll2);
	(*upper_right).enter(*troll3);
	(*upper_left).enter(*troll4);

	Ring* ring = new Ring();
	(*upper_left).drop(*ring);

	Bag* bag = new Bag();
	(*upper_right).drop(*bag);

	environments.push_back(upper_right);
	environments.push_back(upper_left);
	environments.push_back(lower_right);
	environments.push_back(lower_left);

	return environments;
}