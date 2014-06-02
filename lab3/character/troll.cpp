#include "troll.h"

#import "../object/pocket.h"

namespace lab3 {
	
	Troll::Troll(std::string name_, int hp, int mp){
		type = "Troll";
		name = name_;
		hit_points = hp;
		magic_points = mp;
		container = new Pocket();
		go_prob = 0.2;
		fight_prob = 0.1;
		pickup_prob = 0.1;
		drop_prob = 0.1;
	}
	
	void Troll::fight(Character &){

	}
}