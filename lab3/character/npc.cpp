#include "npc.h"
#include "../environment/environment.h"
#include "../object/container.h"
#include <iostream>

namespace lab3 {

	void NPC::action(Environment& env){

		float r = ((float) rand() / (RAND_MAX));
		if (r < go_prob){
			//GO
			std::vector<std::string> directions = env.directions();
			int random_index = rand() % directions.size();
			std::string direction = directions[random_index];
			go(env, direction);

		}

		r = ((float) rand() / (RAND_MAX));
		if (r < fight_prob){
			//FIGHT
			Character* player = env.get_player();
			if (player != NULL){
				fight(*player, env);
			}
		}

		r = ((float) rand() / (RAND_MAX));
		if (r < pickup_prob){
			//PICK UP
			if (env.get_object_names().size() > 0){
				std::vector<std::string> object_names = env.get_object_names();
				int random_index = rand() % object_names.size();
				std::string name = object_names[random_index];
				Object& object = env.get_object(name);
				env.pick_up(object);
				pick_up(object);
			}
		}

		r = ((float) rand() / (RAND_MAX));
		if (r < drop_prob){
			//DROP
			std::vector<Object *> inventory = (*container).get_objects();
			if (inventory.size() > 0){
				int random_index = rand() % inventory.size();
				Object& object = *inventory[random_index];
				env.drop(object);
				drop(object);
			}
		}
	}

	void NPC::fight(Character& player, Environment& env){
		int random_damage = damage + (rand() % damage);
		player.hit(random_damage);
		std::cout << std::endl << name << " hits " << player.get_name() << " for " << random_damage << " damage.";
		if (random_damage > (random_damage*2)-(random_damage/2))
			std::cout << " Critical strike!" << std::endl;
		else
			std::cout << std::endl;

		if (player.get_hit_points() <= 0){
			std::cout << player.get_name() << " dies." << std::endl;
			exit(0);
		}
	}
}