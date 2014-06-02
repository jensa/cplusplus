#include "player.h"
#include "../environment/environment.h"
#include "../object/pocket.h"

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
		container = new Pocket();
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
		    	inventory_command();
	    	} else if (tokens[0] == "pickup"){
	    		executed_command = pickup_command(tokens, env);
    		} else if (tokens[0] == "drop"){
    			executed_command = drop_command(tokens, env);
			} else if (tokens[0] == "use"){
				executed_command = use_command(tokens, env);
			} else if (tokens[0] == "examine"){
				examine_command(tokens, env);
			} else if (tokens[0] == "look"){
				look_command(env);
			} else if (tokens[0] == "directions"){
				directions_command(env);
			} else if (tokens[0] == "quit"){
				exit(0);
		    } else {
		    	std::cout << "Command not recognized." << std::endl;
		    }
		}
	}

	bool Player::go_command(std::vector<std::string> tokens, Environment& env){
		if (tokens.size() == 1){
			std::cout << "You have to specify where to go." << std::endl;
			return false;
		}

		std::vector<std::string> directions = env.directions();
		std::string direction = tokens[1];

		for (int i = 0; i < directions.size(); i++){
			if(directions[i] == direction){
				Environment new_location = go(env, direction);
				std::cout << "You are now in " << new_location.description() << std::endl;
    			return true;
			}
		}

		std::cout << "You can't go to " << direction << " from here." << std::endl;
		return false;
	}

	void Player::inventory_command(){
		std::vector<Object *>& inventory = (*container).get_objects();

		if (inventory.size() > 0){
			int current_weight = (*container).get_current_weight();
			int hold_weight = (*container).get_hold_weight();

	    	std::cout << "Inventory (" << current_weight << "/" << hold_weight << " kg):" << std::endl;
	    	for (int i = 0; i < inventory.size(); i++){
	    		std::cout << (*inventory[i]).get_name() << " (" << (*inventory[i]).get_weight() << " kg)" << std::endl;
	    	}
    	} else {
    		std::cout << "Inventory is empty!" << std::endl;
    	}
	}
	
	bool Player::pickup_command(std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify what object to pick up." << std::endl;
			return false;
		}

		std::string name = tokens[1];
		Object& object = env.get_object(name);

		if (&object != NULL){
			pick_up(object);
			env.pick_up(object);
			std::cout << "You picked up " << name << std::endl;
			return true;
		} else {
			std::cout << "No object named " << name << std::endl;
			return false;
		}	
	}

	bool Player::drop_command(std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify what object to drop." << std::endl;
			return false;
		}
		std::string name = tokens[1];
		std::vector<Object *>& inventory = (*container).get_objects();

		for (int i = 0; i < inventory.size(); i++){
			if ((*inventory[i]).get_name() == name){
				env.drop(*inventory[i]);
				inventory.erase(inventory.begin()+i);
				std::cout << "You dropped " << name << std::endl;
				return true;
			}
		}
		std::cout << "No object named " << name << " in inventory!" << std::endl;
		return false;
	}

	bool Player::use_command(std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify what object to use." << std::endl;
			return false;
		}
		std::string name = tokens[1];
		std::vector<Object *>& inventory = (*container).get_objects();
		for (int i = 0; i < inventory.size(); i++){
			if ((*inventory[i]).get_name() == name){
				(*inventory[i]).use((*this), env);
				return true;
			}
		}
		std::cout << "No object named " << name << " in inventory!" << std::endl;
		return false;
	}

	void Player::examine_command(std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify what object examine." << std::endl;
			return;
		}
		std::string name = tokens[1];
		std::vector<Object *>& inventory = (*container).get_objects();
		for (int i = 0; i < inventory.size(); i++){
			if ((*inventory[i]).get_name() == name){
				std::cout << (*inventory[i]).get_description() << std::endl;
				return;
			}
		}
		std::cout << "No object named " << name << " in inventory!" << std::endl;
	}

	void Player::look_command(Environment & env){
		std::vector<std::string> character_names = env.get_character_names();
		std::vector<std::string> object_names = env.get_object_names();

		if (character_names.size() > 0){
			std::cout << "Characters in this room: " << std::endl;
			for (int i = 0; i < character_names.size(); i++){
				Character& tmp_char = env.get_character(character_names[i]);
				std::cout << tmp_char.get_name() << " (" << tmp_char.get_type() << ")" << std::endl;
			}
		}

		if (object_names.size() > 0){
			std::cout << "\nObjects in this room: " << std::endl;
			for (int i = 0; i < object_names.size(); i++){
				std::cout << object_names[i] << std::endl;
			}
		}
	}

	void Player::directions_command(Environment & env){
		std::vector<std::string> directions = env.directions();
		std::cout << "From " << env.description() << " you can go to: ";
		
		for (int i = 0; i < directions.size(); i++){
			std::cout << directions[i];
			if (i < directions.size()-1)
				std::cout << ", ";
			else 
				std::cout << std::endl;
		}
	}
	
	bool Player::fight_command(std::vector<std::string> tokens, Environment & env){
		return false;
	}

	void Player::fight(Character &){

	}
}