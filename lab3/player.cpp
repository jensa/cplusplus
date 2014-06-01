#include "player.h"

#include <iostream>
#include <sstream>
#include <iterator>

namespace lab3 {

	Player::Player(std::string name, int hp, int mp) {
		type = "Player";
		name = name;
		hit_points = hp;
		magic_points = mp;
	}

	void Player::action(Environment & env) {
		std::string command;
		std::cout << ">" << std::endl;
		std::cin >> command;

		std::istringstream buf(command);
	    std::istream_iterator<std::string> beg(buf), end;
	    std::vector<std::string> tokens(beg, end);

	    if (tokens[0] == "go") {
	    	if (tokens[1] == "north")
	    		go(env, "north");
	    	if (tokens[1] == "south")
	    		go(env, "south");
	    	if (tokens[1] == "east")
	    		go(env, "east");
	    	if (tokens[1] == "west")
	    		go(env, "west");
	    }
	}

	void Player::fight(Character &) {

	}
}