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

		bool executed_command = false;

		while (!executed_command) {
		
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
		    	Environment* new_location;
		    	if (tokens[1] == "north")
		    		new_location = go(env, "north");
		    	else if (tokens[1] == "south")
		    		new_location = go(env, "south");
		    	else if (tokens[1] == "east")
		    		new_location = go(env, "east");
		    	else if (tokens[1] == "west")
		    		new_location = go(env, "west");

		    	if (new_location == NULL)
		    		std::cout << "You can't go " << tokens[1] << " from here." << std::endl;
		    	else
		    		executed_command = true;
		    } else {
		    	std::cout << "Command not recognized." << std::endl;
		    }
		}
	}

	void Player::fight(Character &) {

	}
}