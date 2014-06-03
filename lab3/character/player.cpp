#include "player.h"
#include "../environment/environment.h"
#include "../object/pocket.h"
#include "../object/weapon.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <cstring>

namespace lab3 {

	Player::Player(std::string name_, int hp){
		type = "Player";
		name = name_;
		hit_points = hp;
		container = new Pocket();
		weapon = new Weapon(5, 1, "fists", "these are your fists");
		damage = weapon->get_damage();
	}

	bool Player::action(Environment & env){

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
		   	} else if (tokens[0] == "fight"){
		   		executed_command = fight_command(tokens, env);
		   	} else if (tokens[0] == "talk"){
		   		executed_command = talk_command(tokens, env);
		    } else if (tokens[0] == "inventory"){
		    	inventory_command();
	    	} else if (tokens[0] == "pickup"){
	    		executed_command = pickup_command(tokens, env);
    		} else if (tokens[0] == "drop"){
    			executed_command = drop_command(tokens, env);
			} else if (tokens[0] == "use"){
				executed_command = use_command(tokens, env);
			} else if (tokens[0] == "examine"){
				examine_command(tokens);
			} else if (tokens[0] == "look"){
				look_command(env);
			} else if (tokens[0] == "directions"){
				directions_command(env);
			} else if (tokens[0] == "quit"){
				return false;
		    } else {
		    	std::cout << "Command not recognized." << std::endl;
				return true;
		    }
		}
		return true;
	}

	bool Player::go_command(const std::vector<std::string> tokens, Environment& env){
		if (tokens.size() == 1){
			std::cout << "You have to specify where to go." << std::endl;
			return false;
		}

		std::vector<std::string> directions = env.directions();
		std::string direction = tokens[1];

		for (int i = 0; i < directions.size(); i++){
			if(directions[i] == direction){
				Environment& new_location = go(env, direction);
				look_command(new_location);
    			return true;
			}
		}

		std::cout << "You can't go to " << direction << " from here." << std::endl;
		return false;
	}

	bool Player::fight_command(const std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify who you want to fight." << std::endl;
			return false;
		}

		std::string name = tokens[1];
		Character* character = env.get_character(name);

		if (character != NULL){
			fight(*character, env);
			return true;
		} else {
			std::cout << "No character named " << name << " in this environment." << std::endl;
			return false;
		}
	}

	bool Player::talk_command(const std::vector<std::string> tokens, Environment & env){
		if (tokens.size() == 1){
			std::cout << "You have to specify who you want to talk to." << std::endl;
			return false;
		}

		std::string name = tokens[1];
		Character& character = *env.get_character(name);

		if (&character != NULL){
			std::cout << character.get_name() << " says: '" << character.talk_to(*this, env) << "'" << std::endl;
			return true;
		} else {
			std::cout << "No character named " << name << " in this environment." << std::endl;
			return false;
		}
	}

	void Player::inventory_command() const{
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
		Object* object = env.get_object(name);

		if (object != NULL){
			std::cout << get_container().get_current_weight() << std::endl;
			std::cout << (*object).get_weight() << std::endl;
			if (get_container().get_current_weight() + (*object).get_weight() > get_container().get_hold_weight()){
				std::cout << "You don't have enough room in your inventory for " << name << "." << std::endl;
				return false;
			};
			pick_up(*object);
			env.pick_up(*object);
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
				get_container().remove(*inventory[i]);
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

	void Player::examine_command(const std::vector<std::string> tokens) const{
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

	void Player::look_command(const Environment & env) const{
		std::cout << env.description() << std::endl;

		std::vector<std::string> character_names = env.get_character_names();
		std::vector<std::string> object_names = env.get_object_names();

		if (character_names.size() > 0){
			std::cout << "\nCharacters in this environment: " << std::endl;
			for (int i = 0; i < character_names.size(); i++){
				Character& tmp_char = (*env.get_character(character_names[i]));
				if(tmp_char.get_name() != name)
					std::cout << tmp_char.get_name() << " (" << tmp_char.get_type() << ")" << std::endl;
			}
		}

		if (object_names.size() > 0){
			std::cout << "\nObjects in this environment: " << std::endl;
			for (int i = 0; i < object_names.size(); i++){
				std::cout << object_names[i] << std::endl;
			}
		}
	}

	void Player::directions_command(const Environment & env) const{
		std::vector<std::string> directions = env.directions();
		std::cout << "Directions: ";
		
		for (int i = 0; i < directions.size(); i++){
			std::cout << directions[i];
			if (i < directions.size()-1)
				std::cout << ", ";
			else 
				std::cout << std::endl;
		}
	}

	void Player::fight(Character & c, Environment& env){
		if (c.get_type() == "Player"){
			std::cout << "You can't fight yourself." << std::endl;
			return;
		}

		int random_damage = get_damage() + (rand() % get_damage());
		c.hit(random_damage);
		std::cout << name << " hits " << c.get_name() << " for " << random_damage << " damage.";
		if (random_damage > (random_damage*2)-(random_damage/2))
			std::cout << " Critical strike!" << std::endl;
		else
			std::cout << std::endl;

		if (c.get_hit_points() <= 0){
			std::cout << c.get_name() << " dies." << std::endl;
			std::vector<Object *> character_inventory = c.get_container().get_objects();
			std::cout << c.get_name() << " drops: ";
			if (character_inventory.size() > 0){
				for (int i = 0; i < character_inventory.size(); i++){
					Object& dropped_object = *character_inventory[i];
					std::cout << dropped_object.get_name();
					env.drop(dropped_object);
				}
				std::cout << std::endl;
			}
			Weapon* dropped_weapon = c.get_weapon();
			env.drop(*dropped_weapon);
			std::cout << dropped_weapon->get_name() << std::endl;
			env.leave(c);
		}
	}

	const std::string Player::talk_to(Character &, Environment &){
		return "";
	}
}