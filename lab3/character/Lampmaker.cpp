#include "lampmaker.h"

#include "../object/pocket.h"

namespace lab3 {
	
	Lampmaker::Lampmaker(std::string name_, int hp, int dmg){
		type = "Lamp Maker";
		name = name_;
		hit_points = hp;
		damage = dmg;
		container = new Pocket();
		go_prob = 0;
		fight_prob = 0;
		pickup_prob = 0;
		drop_prob = 0;
	}
}