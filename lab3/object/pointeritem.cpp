#include "pointeritem.h"

namespace lab3{

Pointeritem::Pointeritem(void)
{
	name = "voidpointer";
	description = "You have no idea what this is";
	weight = 1;
}


Pointeritem::~Pointeritem(void)
{
}

bool Pointeritem::use(Character & character , Environment & env){
	if(name == "voidpointer"){
		std::cout << "You cast the void pointer to a function pointer" << std::endl;
		name = "functionpointer";
		return true;
	} else if(name == "functionpointer"){
		std::cout << "The function pointer points to exit()! Goodbye, hero!" << std::endl;
		return false;
	}
	return true;
}

}