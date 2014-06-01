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

		bool executed_command = false;

		while (!executed_command){
		
			std::cout << "\n>";

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
			} else if (tokens[0] == "look"){
				executed_command = look_command(env);
			} else if (tokens[0] == "quit"){
				exit(0);
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
    		std::cout << "You are now in " << (*new_location).description() << std::endl;
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
			std::cout << "You picked up " << name << std::endl;
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
				std::cout << "You dropped " << name << std::endl;
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

	bool Player::look_command(Environment & env){
		std::vector<Character *> characters = env.getCharacters();
		std::vector<Object *> objects = env.getObjects();

		if (characters.size() > 0){
			std::cout << "Characters in this room: ";
			for (int i = 0; i < characters.size(); i++){
				std::cout << (*characters[i]).get_name() << " (" << (*characters[i]).get_type() << ")" << std::endl;
			}
		}

		if (objects.size() > 0){
			std::cout << "Objects in this room: ";
			for (int i = 0; i < objects.size(); i++){
				std::cout << (*objects[i]).get_name() << std::endl;
			}
		}
		return true;
	}
	
	bool Player::fight_command(std::vector<std::string> tokens, Environment & env){
		return false;
	}

	void Player::fight(Character &){

	}
}