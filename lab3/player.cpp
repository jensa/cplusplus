#include "player.h"

#include "environment.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

namespace lab3 {

	Player::Player(std::string name_, int hp, int mp) {
		type = "Player";
		name = name_;
		hit_points = hp;
		magic_points = mp;
	}

	void Player::action(Environment & env) {

		std::cout << "Location: " << env.description() << std::endl;
		
		std::cout << ">";

		char command[256];

		std::cin.getline(command, 256);

		std::string command_string = std::string(command);

		std::stringstream ss(command_string);
		std::string s;
		std::vector<std::string> tokens;

		while (getline(ss, s, ' ')) {
			tokens.push_back(s);
		}

	    if (tokens[0] == "go") {
	    	if (tokens[1] == "north")
	    		go(env, "north");
	    	else if (tokens[1] == "south")
	    		go(env, "south");
	    	else if (tokens[1] == "east")
	    		go(env, "east");
	    	else if (tokens[1] == "west")
	    		go(env, "west");
	    }
	}

	void Player::fight(Character &) {

	}
}