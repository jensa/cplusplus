#include <iostream>
#include <vector>
#include <string>
#include <map>

class Character;
class Object;

namespace lab3{

	class Environment {
		std::map<std::string, Environment> neighbor_map;
		std::vector<std::string> neighbors;
		std::string description_string;
	public:
		Environment(std::string description);
		std::string directions();
		Environment neighbor(std::string direction);
		std::string description() const;
		void enter(Character &);
		void leave(Character &);
		void pick_up(Object &);
		void drop(Object &);
	};

}