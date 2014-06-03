#include "pocket.h"
#include "../character/character.h"

namespace lab3{
	Pocket::Pocket(){
		name = "pocket";
		description = "A pocket that can hold a total weight of 5 kg.";
		weight = 1;
		hold_weight = 5;
		current_weight = 0;
	}

	Pocket::~Pocket(){
		for (int i = 0; i < objects.size(); i++){
			delete objects[i];
		}
	}

	void Pocket::use(Character & character, Environment & env){
		character.set_container(this);
		std::cout << "Player inventory can now hold a total weight of " << get_hold_weight() << "." << std::endl;
	}
}