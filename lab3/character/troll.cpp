#include "troll.h"

#include "../object/bag.h"

namespace lab3 {
	
	Troll::Troll(std::string name_, int hp){
		type = "Troll";
		name = name_;
		hit_points = hp;
		container = new Bag();
		go_prob = 0.2;
		fight_prob = 0.8;
		pickup_prob = 0.1;
		drop_prob = 0.1;
	}
}