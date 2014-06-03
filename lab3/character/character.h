#ifndef CHAR_H
#define CHAR_H

#include <iostream>
#include <vector>
#include "../object/object.h"
#include "../object/weapon.h"

namespace lab3 {

	class Environment;
	class Container;
	class Weapon;

	class Character {
	public:
		const std::string get_type() const;
		const std::string get_name() const;
		const int get_hit_points() const;

		void pick_up(Object &);
		void drop(Object &);
		void hit(const int); 
		Environment& go(Environment &, const std::string);
		Container& get_container() const;
		void set_container(Container *);

		void set_weapon(Weapon *, Character &, Environment &);

		const int get_damage() const;
		virtual void action(Environment &) = 0;
		virtual void fight(Character &, Environment &) = 0;
		virtual const std::string talk_to(Character &, Environment &) = 0;

	protected:
		std::string type;
		std::string name;
		int hit_points;
		int damage;
		Container* container;
		Weapon* weapon;
	};
}
#endif