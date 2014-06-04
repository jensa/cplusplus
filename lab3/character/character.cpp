#include "character.h"
#include "../environment/environment.h"
#include "../object/container.h"

namespace lab3 {

	const std::string Character::get_type() const{
		return type;
	}

	const std::string Character::get_name() const{
		return name;
	}

	const int Character::get_hit_points() const{
		return hit_points;
	}

	void Character::pick_up(Object& o){
		(*container).add(o);
	}

	void Character::drop(Object& o){
		(*container).remove(o);
	}

	Environment& Character::go(Environment& env, const std::string direction){
		Environment& neighbor = *env.neighbor(direction);
		env.leave(*this);
		neighbor.enter(*this);
		
		return neighbor;
	}

	Container& Character::get_container() const{
		return *container;
	}

	void Character::set_container(Container * new_container){
		
		std::vector<Object *>& inventory = (*container).get_objects();
		for (int i = 0; i < inventory.size(); i++){
			(*new_container).add(*inventory[i]);
		}
		inventory.clear();
		Container* old_container = container;
		delete old_container;
		container = new_container;
	}

	void Character::hit(int damage){
		hit_points -= damage;
	}

	const std::string Character::talk_to(Character &, Environment &){
		return "";
	}

	void Character::set_weapon(Weapon * weap, Character & character, Environment & env){
		if((*weapon).get_name() != "fists"){
			Container & container = character.get_container();
			if(container.get_current_weight() + (*weapon).get_weight() > container.get_hold_weight()){
				env.drop(*weapon);
			} else{
				pick_up(*weapon);
			}
		} else {
			Weapon* old_weapon = weapon;
			delete old_weapon;
		}
		weapon = weap;
		damage = (*weap).get_damage();
		drop(*weap);
		std::cout << "You equipped the " << weapon->get_name() << ". it has a damage value of " << weapon->get_damage() << "." << std::endl;
	}

	const int Character::get_damage() const{
		return damage;
	}

	Weapon* Character::get_weapon(){
		return weapon;
	}

	void Character::set_alive(bool alive_){
		alive = alive_;
	}

	const bool Character::get_alive(){
		return alive;
	}
}