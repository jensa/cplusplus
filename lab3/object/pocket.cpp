#include "pocket.h"
#include "../character/character.h"

namespace lab3{
	Pocket::Pocket(){
		name = "pocket";
		weight = 1;
		hold_weight = 5;
		current_weight = 0;
	}

	void Pocket::use(Character & character, Environment & env){
		character.set_container(this);
		std::cout << "Player inventory can now hold a total weight of " << get_hold_weight() << "." << std::endl;
	}
}