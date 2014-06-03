#include "lampmaker.h"

#include "../object/pocket.h"
#include "../object/lamp.h"
#include "../environment/environment.h"

namespace lab3 {
	
	Lampmaker::~Lampmaker(){
		delete container;
		delete weapon;
	}

	Lampmaker::Lampmaker(std::string name_, int hp, Weapon* weapon_){
		type = "Lamp Maker";
		name = name_;
		hit_points = hp;
		container = new Pocket();
		go_prob = 0;
		fight_prob = 0;
		pickup_prob = 0;
		drop_prob = 0;
		weapon = weapon_;
	}

	const std::string Lampmaker::talk_to(Character & character, Environment& env){
		Lamp* lamp = new Lamp();
		env.drop(*lamp);
		env.leave(*this);
		return "Hello. I am the lampmaker. I am of course dying. I see that you are original enough to take this lamp. Take it. just take it please. Urghhh...";
	}
}