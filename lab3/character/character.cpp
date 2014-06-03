#include "character.h"
#include "../environment/environment.h"
#include "../object/container.h"

namespace lab3 {

	const std::string Character::get_type() const{
		return type;
	}

	const std::string Character::get_name() const{
		return name;
	}

	const int Character::get_hit_points() const{
		return hit_points;
	}

	const int Character::get_damage() const{
		return damage;
	}

	void Character::pick_up(Object& o){
		(*container).add(o);
	}

	void Character::drop(Object& o){
		(*container).remove(o);
	}

	Environment& Character::go(Environment& env, const std::string direction){
		Environment& neighbor = *env.neighbor(direction);
		env.leave(*this);
		neighbor.enter(*this);
		
		return neighbor;
	}

	Container& Character::get_container() const{
		return *container;
	}

	void Character::set_container(Container * new_container){
		
		std::vector<Object *>& inventory = (*container).get_objects();
		for (int i = 0; i < inventory.size(); i++){
			(*new_container).add(*inventory[i]);
		}
		container = new_container;
	}

	void Character::hit(int damage){
		hit_points -= damage;
	}
}