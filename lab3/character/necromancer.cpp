#include "necromancer.h"

#include "../object/pocket.h"

namespace lab3 {
	
	Necromancer::~Necromancer(){
		if(alive){
			delete weapon;
		}
		delete container;
	}

	Necromancer::Necromancer(std::string name_, int hp, Weapon * weapon_){
		type = "Necromancer";
		name = name_;
		hit_points = hp;
		container = new Pocket();
		go_prob = 0.0;
		fight_prob = 1.0;
		pickup_prob = 0.0;
		drop_prob = 0.0;
		weapon = weapon_;
		damage = weapon->get_damage();
		alive = true;
	}

	const std::string Necromancer::talk_to(Character &, Environment &){
		return "All I wanna do is eat your brainz...";
	}
}