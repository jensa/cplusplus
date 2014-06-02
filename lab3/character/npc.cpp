#include "npc.h"
#include "../environment/environment.h"
#include <iostream>

namespace lab3 {

	void NPC::action(Environment& env){

		float r = ((float) rand() / (RAND_MAX));

		if (r < 0.50){
			//GO
			std::vector<std::string> directions = env.directions();
			int randomIndex = rand() % directions.size();
			std::string direction = directions[randomIndex];
			go(env, directions[randomIndex]);

		} else if (r < 0.60){
			//FIGHT
		} else if (r < 0.70){
			//PICK UP
		} else if (r < 0.80){
			//DROP
		} else {
			//TALK TO
		}
	}
}