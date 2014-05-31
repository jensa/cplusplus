#include "character.h"

namespace lab3 {

	std::string Character::get_type() const {
		return type;
	}

	std::string Character::get_name() const {
		return name;
	}

	void Character::go(std::string direction) {
		set_current_location(current_location.neighbor(direction));
	}

	void Character::set_current_location(Environment env) {
		current_location = env;
	}

	void Character::pick_up(Object o) {
		current_location.pick_up(o);
		items.push_back(o);
	}

	void Character::drop(Object o) {
		current_location.drop(o);
		for (int i = 0; i < items.size(); i++) {
			if (&items[i] == &o) {
				items.erase(items.begin()+i);
			}
		}
	}
}