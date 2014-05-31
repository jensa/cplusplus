#include <iostream>
#include <vector>
#include "environment.h"
#include "object.h"

namespace lab3 {
	class Character {
	public:
		std::string get_type() const;
		std::string get_name() const;
		void pick_up(Object);
		void drop(Object);
		void set_current_location(Environment);
		void go(std::string);

	protected:
		std::string type;
		std::string name;
		int hit_points;
		int mana_points;
		std::vector<Object> items;
		Environment current_location;
	};
}