#include <vector>
#include <iostream>

namespace lab3{

	class Environment {
	public:
		Environment();
		std::string directions();
		Environment neighbor(std::string direction);
		std::string description() const;
		//enter(Character c)
		//leave(character)
		//void pick_up(Object);
		//void drop(Object);
	};

}