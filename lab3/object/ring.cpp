#include "ring.h"

namespace lab3{
	Ring::Ring(){
		name = "ring";
		weight = 1;
	}

	void Ring::use(Character &, Environment &){
		std::cout << "You look at the ring. Very shine. Wow." << std::endl;
	}
}