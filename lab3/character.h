#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <vector>
#include "environment.h"


namespace lab3 {
	class Character {
	public:
		Character();
		Character(std::string, std::string, int, int);
		std::string get_type() const;
		std::string get_name() const;
		void action();
		void go(std::string);
		void fight(Character);
		void pick_up(Object);
		void drop(Object);
		void talk_to(Character);
		void set_current_location(Environment);

	private:
		std::string type;
		std::string name;
		std::vector<Object> items;
		Environment current_location;
	};
}

#endif