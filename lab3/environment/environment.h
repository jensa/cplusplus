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
		const std::vector<std::string> directions() const;
		Environment* neighbor(const std::string direction);
		void set_neighbor(const std::string direction, Environment* neighbor);
		const std::string description() const;
		void enter(Character &);
		void leave(Character &);
		Character& get_character(const std::string) const;
		Character* get_player() const;
		const std::vector<std::string> get_character_names() const;
		Object& get_object(const std::string) const;
		const std::vector<std::string> get_object_names() const;
		void pick_up(Object &);
		void drop(Object &);
		virtual void interact(const Object &);
	};
}