#include "character.h"
#include "../environment/environment.h"
#include "../object/container.h"

namespace lab3 {

	std::string Character::get_type(){
		return type;
	}

	std::string Character::get_name(){
		return name;
	}

	void Character::pick_up(Object* o){
		(*container).add(o);
	}

	void Character::drop(Object* o){
		(*container).remove(o);
	}

	Environment* Character::go(Environment& env, std::string direction){
		Environment* neighbor = env.neighbor(direction);
		if (neighbor != NULL){
			env.leave(*this);
			(*neighbor).enter(*this);
		}
		return neighbor;
	}

	Container& Character::get_container(){
		return *container;
	}

	void Character::set_container(Container * new_container){
		
		std::vector<Object *>& inventory = (*container).get_objects();
		for (int i = 0; i < inventory.size(); i++){
			(*new_container).add(inventory[i]);
		}
		container = new_container;
	}

	void Character::talk_to(Character &){

	}
}