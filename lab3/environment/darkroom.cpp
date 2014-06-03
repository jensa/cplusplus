#include "darkroom.h"

namespace lab3{
Darkroom::Darkroom(void)
{
	lamped = false;
}


Darkroom::~Darkroom(void)
{

}

void Darkroom::interact(Object & o){
	std::cout << typeid(o).name();
}
}