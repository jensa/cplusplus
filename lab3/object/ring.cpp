#include "ring.h"

namespace lab3{
	Ring::Ring(){
		name = "ring";
		description = "A golden ring. Very shine. Wow.";
		weight = 1;
	}

	void Ring::use(Character &, Environment &){
		std::cout << "You try to use the ring. Nothing happens." << std::endl;
	}
}