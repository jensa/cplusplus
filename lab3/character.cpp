#include "character.h"

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
		for (int i = 0; i < items.size(); i++) {
			if (&o == items[i]) {
				items.erase(items.begin()+i);
			}
		}
	}

	void Character::go(Environment& env, std::string direction) {
		
	}

	void Character::talk_to(Character &) {

	}
}