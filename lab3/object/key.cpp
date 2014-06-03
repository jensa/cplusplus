#include "key.h"
#include "../environment/environment.h"

namespace lab3{

Key::Key(void)
{
	name = "key";
	description = "This key look key-y";
	weight = 1;
}


Key::~Key(void)
{
}

void Key::use(Character & character , Environment & env){
	env.interact(*this);
}

}