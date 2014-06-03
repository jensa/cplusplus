#ifndef CHAR_H
#define CHAR_H

#include <iostream>
#include <vector>
#include "../object/object.h"

namespace lab3 {

	class Environment;
	class Container;

	class Character {
	public:
		const std::string get_type() const;
		const std::string get_name() const;
		const int get_hit_points() const;
		const int get_damage() const;

		void pick_up(Object &);
		void drop(Object &);
		const std::string talk_to(const Character &) const;
		void hit(const int); 
		Environment& go(Environment &, const std::string);
		Container& get_container() const;
		void set_container(Container *);
		
		virtual void action(Environment &) = 0;
		virtual void fight(Character &, Environment &) = 0;
	
	protected:
		std::string type;
		std::string name;
		int hit_points;
		int damage;
		Container* container;
	};
}
#endif