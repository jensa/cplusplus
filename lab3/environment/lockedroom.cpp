#include "lockedroom.h"

namespace lab3{
Lockedroom::Lockedroom(void)
{

}

Lockedroom::Lockedroom(std::string locked_desc, std::string open_desc, Environment* env){
	description_string = locked_desc;
	open_description = open_desc;
	unlocked_neighbor = env;
}


Lockedroom::~Lockedroom(void){
	for (int i = 0; i < objects.size(); i++){
		delete objects[i];
	}
	for (int i = 0; i < characters.size(); i++){
		delete characters[i];
	}
}

	void Lockedroom::interact(const Object & o){
		if (o.get_name() == "key"){
			set_description(open_description);
			set_neighbor("east", unlocked_neighbor);
			std::cout << "The door is now unlocked" << std::endl;
		} else{
			Environment::interact(o);
		}
	}

}
