#include "necromancer.h"

#include "../object/pocket.h"

namespace lab3 {
	
	Necromancer::Necromancer(std::string name_, int hp, int dmg){
		type = "Necromancer";
		name = name_;
		hit_points = hp;
		damage = dmg;
		container = new Pocket();
		go_prob = 0.2;
		fight_prob = 0.9;
		pickup_prob = 0.1;
		drop_prob = 0;
	}
}