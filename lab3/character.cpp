#include "character.h"
#include "environment.h"

namespace lab3 {

	std::string Character::get_type() {
		return type;
	}

	std::string Character::get_name() {
		return name;
	}

	void Character::pick_up(Object & o) {
		items.push_back(&o);
	}

	void Character::drop(Object & o) {
		for (std::vector<Object *>::iterator it=items.begin();it!=items.end();){
		   if(&o == (*it)) 
		      it = items.erase(it);
		  else 
		      ++it;
		}
	}

	void Character::go(Environment& env, std::string direction) {
		env.leave(*this);
		Environment neighbor = env.neighbor(direction);
		neighbor.enter(*this);
	}

	void Character::talk_to(Character &) {

	}
}