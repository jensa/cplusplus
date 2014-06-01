#include "ring.h"

namespace lab3{
	Ring::Ring(std::string name_){
		name = name_;
	}

	void Ring::use(Environment &){
		std::cout << "You look at the ring. Very shine. Wow." << std::endl;
	}
}