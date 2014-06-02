#include "bag.h"
#include "../character/character.h"

namespace lab3{
	Bag::Bag(){
		name = "bag";
		weight = 1;
		hold_weight = 20;
		current_weight = 0;
	}

	void Bag::use(Character & character, Environment & env){
		character.set_container(this);
		character.get_container().remove(this);
		std::cout << "Player inventory can now hold a total weight of " << get_hold_weight() << " kg." << std::endl;
	}
}