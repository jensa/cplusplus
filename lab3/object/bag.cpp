#include "bag.h"
#include "../character/character.h"

namespace lab3{
	Bag::Bag(){
		name = "bag";
		description = "A bag that can hold a total weight of 20 kg.";
		weight = 1;
		hold_weight = 20;
		current_weight = 0;
	}

	Bag::~Bag(){
		for (int i = 0; i < objects.size(); i++){
			delete objects[i];
		}
	}

	bool Bag::use(Character & character, Environment & env){
		character.set_container(this);
		character.get_container().remove(*this);
		std::cout << "Player inventory can now hold a total weight of " << get_hold_weight() << " kg." << std::endl;
		return true;
	}
}