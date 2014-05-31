#include <vector>
#include <iostream>

namespace lab3{

	class Environment {
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

int main(){

	std::cout << "HI!";
}