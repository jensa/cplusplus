#include "npc.h"
#include "../environment/environment.h"
#include "../object/container.h"
#include <iostream>

namespace lab3 {

	void NPC::action(Environment& env){

		float r = ((float) rand() / (RAND_MAX));

		if (r < 0.50){
			//GO
			std::vector<std::string> directions = env.directions();
			int random_index = rand() % directions.size();
			std::string direction = directions[random_index];
			go(env, direction);

		} else if (r < 0.60){
			//FIGHT
		} else if (r < 0.70){
			//PICK UP
			if (env.get_object_names().size() > 0){
				std::vector<std::string> object_names = env.get_object_names();
				int random_index = rand() % object_names.size();
				std::string name = object_names[random_index];
				Object& object = env.get_object(name);
				env.pick_up(object);
				pick_up(object);
			}
		} else if (r < 0.80){
			std::vector<Object *> inventory = (*container).get_objects();
			if (inventory.size() > 0){
				int random_index = rand() % inventory.size();
				Object& object = *inventory[random_index];
				env.drop(object);
				drop(object);
			}
		} else {
			//TALK TO
		}
	}
}