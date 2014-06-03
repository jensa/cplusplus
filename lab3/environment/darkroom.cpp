#include "darkroom.h"

namespace lab3{
Darkroom::Darkroom(const std::string desc)
{
	lamped = false;
	description_string = desc;
}


Darkroom::~Darkroom(void)
{

}

void Darkroom::interact(const Object & o){
	std::cout << typeid(o).name();
	set_description("OH MY GOD everything is super bright! You see an ominous door.");
}
}