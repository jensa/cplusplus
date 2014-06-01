#include "player.h"

#include "environment.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

namespace lab3 {

	Player::Player(std::string name_, int hp, int mp){
		type = "Player";
		name = name_;
		hit_points = hp;
		magic_points = mp;
	}

	void Player::action(Environment & env){

		std::cout << env.description() << std::endl;

		bool executed_command = false;

		while (!executed_command){
		
			std::cout << ">";

			char command[256];

			std::cin.getline(command, 256);

			if (std::strcmp(command, "") == 0) {
				continue;
			}

			std::string command_string = std::string(command);

			std::stringstream ss(command_string);
			std::string s;
			std::vector<std::string> tokens;

			while (getline(ss, s, ' ')){
				tokens.push_back(s);
			}

		    if (tokens[0] == "go"){
		   		executed_command = go_command(tokens, env);
		    } else if (tokens[0] == "inventory"){
		    	executed_command = inventory_command();
	    	} else if (tokens[0] == "pickup"){
	    		executed_command = pickup_command(tokens, env);
    		} else if (tokens[0] == "drop"){
    			executed_command = drop_command(tokens, env);
			} else if (tokens[0] == "use"){
				executed_command = use_command(tokens, env);
		    } else {
		    	std::cout << "Command not recognized." << std::endl;
		    }
		}
	}

	bool Player::go_command(std::vector<std::string> tokens, Environment& env){
		Environment* new_location;
    	if (tokens[1] == "north")
    		new_location = go(env, "north");
    	else if (tokens[1] == "south")
    		new_location = go(env, "south");
    	else if (tokens[1] == "east")
    		new_location = go(env, "east");
    	else if (tokens[1] == "west")
    		new_location = go(env, "west");

    	if (new_location != NULL) {
    		return true;
    	} else {
    		std::cout << "You can't go " << tokens[1] << " from here." << std::endl;
    		return false;
    	}
	}

	bool Player::inventory_command(){
		if (items.size() > 0){
	    	std::cout << "Inventory:" << std::endl;
	    	for (int i = 0; i < items.size(); i++){
	    		std::cout << (*items[i]).get_name() << std::endl;
	    	}
    	} else {
    		std::cout << "Inventory is empty!" << std::endl;
    	}
    	return true;
	}
	
	bool Player::pickup_command(std::vector<std::string> tokens, Environment & env){
		std::string name = tokens[1];
		Object* object = env.getObject(name);

		if (object != NULL){
			pick_up(object);
			env.pick_up(*object);
			return true;
		} else {
			std::cout << "No object named " << name << std::endl;
			return false;
		}	
	}

	bool Player::drop_command(std::vector<std::string> tokens, Environment & env){
		std::string name = tokens[1];

		for (int i = 0; i < items.size(); i++){
			if ((*items[i]).get_name() == name){
				env.drop(*items[i]);
				items.erase(items.begin()+i);
				return true;
			}
		}
		std::cout << "No object named " << name << " in inventory!" << std::endl;
		return false;
	}

	bool Player::use_command(std::vector<std::string> tokens, Environment & env){
		std::string name = tokens[1];

		for (int i = 0; i < items.size(); i++){
			if ((*items[i]).get_name() == name){
				(*items[i]).use(env);
				return true;
			}
		}
		std::cout << "No object named " << name << " in inventory!" << std::endl;
		return false;
	}
	
	bool Player::fight_command(std::vector<std::string> tokens, Environment & env){
		return false;
	}

	void Player::fight(Character &){

	}
}