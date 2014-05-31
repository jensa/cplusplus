#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "object.h"
#include "character.h"
#include "object.h"

namespace lab3{

	class Environment {
		std::map<std::string, Environment> neighbor_map;
		std::string description_string;
		std::vector<Character> characters;
		std::vector<Object> items;

	public:
		Environment();
		Environment(std::string description);
		std::string directions();
		Environment neighbor(std::string direction);
		void set_neighbor(std::string direction, Environment neighbor);
		std::string description() const;
		void enter(Character &);
		void leave(Character &);
		Character getCharacter(std::string);
		void pick_up(Object &);
		void drop(Object &);
	};
}