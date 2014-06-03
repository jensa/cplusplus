#include "weapon.h"
#include "../character/character.h"

namespace lab3{
Weapon::Weapon(void)
{
}


Weapon::~Weapon(void)
{
}

Weapon::Weapon(int dmg, int weapon_weight, std::string weapon_name, std::string desc){
	weight = weapon_weight;
	description = desc;
	name = weapon_name;
	damage = dmg;
}

int Weapon::get_damage(){
	return damage;
}

void Weapon::use(Character & character, Environment & env){
	character.set_weapon(this, character, env);
}


}
