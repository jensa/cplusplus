#include "key.h"
#include "../environment/environment.h"

namespace lab3{

Key::Key(void)
{
	name = "key";
	description = "This key looks key-y";
	weight = 1;
}


Key::~Key(void)
{
}

bool Key::use(Character & character , Environment & env){
	env.interact(*this);
	return true;
}

}