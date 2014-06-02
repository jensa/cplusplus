#include "troll.h"

#import "../object/pocket.h"

namespace lab3 {
	
	Troll::Troll(std::string name_, int hp, int mp){
		type = "Troll";
		name = name_;
		hit_points = hp;
		magic_points = mp;
		container = new Pocket();
	}
	
	void Troll::fight(Character &){

	}
}