#include "dragon.h"
#include "../object/bag.h"

namespace lab3{
Dragon::Dragon(void)
{
}

Dragon::~Dragon()
{
	if (alive){
		delete weapon;
	}
	delete container;
}

Dragon::Dragon(std::string char_name, int hit_points_, Weapon* weap){
	type = "Dragon";
	name = char_name;
	hit_points = hit_points_;
	container = new Bag();
	go_prob = 0.0;
	fight_prob = 1.0;
	pickup_prob = 0.0;
	drop_prob = 0.0;
	weapon = weap;
	damage = weap->get_damage();
	alive = true;
}

const std::string Dragon::talk_to(Character &, Environment &){
		return "\033[1;31m YOU MUST DIE!! ROAR...\033[0m";
}

}