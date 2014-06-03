#include "lamp.h"
#include "../environment/environment.h"

namespace lab3{
Lamp::Lamp(void)
{
	name = "lamp";
	description = "this lamp is REALLY old.";
	weight = 1;
}


Lamp::~Lamp(void)
{
}

bool Lamp::use(Character & character, Environment & env){
	env.interact(*this);
	return true;
}

}