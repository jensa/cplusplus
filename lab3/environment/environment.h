#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../object/object.h"
#include "../character/character.h"
#include "../object/object.h"

namespace lab3{

	class Environment {
		std::map<std::string, Environment*> neighbor_map;
		std::string description_string;
		std::vector<Character *> characters;
		std::vector<Object *> objects;

	public:
		Environment();
		Environment(std::string description);
		std::vector<std::string> directions();
		Environment* neighbor(std::string direction);
		void set_neighbor(std::string direction, Environment* neighbor);
		std::string description() const;
		void enter(Character &);
		void leave(Character &);
		Character& get_character(std::string);
		Character* get_player();
		std::vector<std::string> get_character_names();
		Object& get_object(std::string);
		std::vector<std::string> get_object_names();
		void pick_up(Object &);
		void drop(Object &);
	};
}