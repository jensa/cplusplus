#include "troll.h"

#include "../object/bag.h"

namespace lab3 {

	Troll::~Troll(){
		delete container;
		delete weapon;
	}
	
	Troll::Troll(std::string name_, int hp, Weapon* wep){
		type = "Troll";
		name = name_;
		hit_points = hp;
		container = new Bag();
		go_prob = 0.2;
		fight_prob = 0.8;
		pickup_prob = 0.1;
		drop_prob = 0.1;
		weapon = wep;
		damage = wep->get_damage();
	}

	const std::string Troll::talk_to(Character &, Environment &){
		return "\033[1;31mlolfi rodolfi\033[0m";
	}
}