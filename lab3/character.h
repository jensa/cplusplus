#ifndef CHAR_H
#define CHAR_H

#include <iostream>
#include <vector>
#include "object.h"

namespace lab3 {

	class Environment;
	class Container;

	class Character {
	public:
		std::string get_type();
		std::string get_name();

		void pick_up(Object *);
		void drop(Object *);
		void talk_to(Character &);
		Environment* go(Environment &, std::string);
		Container& get_container();
		void set_container(Container *);
		
		virtual void action(Environment &) = 0;
		virtual void fight(Character &) = 0;
	
	protected:
		std::string type;
		std::string name;
		int hit_points;
		int magic_points;
		Container* container;
	};
}
#endif