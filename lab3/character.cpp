#include "character.h"

namespace lab3 {
	
	Character::Character() {

	}

	Character::Character(std::string type, std::string name, int hit_points, int mana) {

	}

	std::string Character::get_type() const {
		return type;
	}

	std::string Character::get_name() const {
		return name;
	}

	void Character::action() {

	}

	void Character::go(std::string direction) {

	}

	void Character::fight(Character) {

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

	void Character::talk_to(Character) {

	}

	void set_current_location(Environment env) {
		current_location = env;
	}
}