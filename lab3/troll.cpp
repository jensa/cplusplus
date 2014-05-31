#include "troll.h"

namespace lab3 {
	Troll::Troll(std::string _name, int hp, int mp) {
		type = "Troll";
		name = _name;
		hit_points = hp;
		mana_points = mp;
	}
	
	void action() {

	}
	
	void fight(Character&) {

	}
	
	void talk_to(Character&) {

	}
}
