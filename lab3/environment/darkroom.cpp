#include "darkroom.h"

namespace lab3{
	Darkroom::Darkroom(const std::string light, std::string dark, Environment* light_env)
{
	lamped = false;
	dark_desc = dark;
	description_string = dark;
	light_desc = light;
	light_environment = light_env;
}


Darkroom::~Darkroom(void)
{

}

void Darkroom::interact(const Object & o){
	if (o.get_name() == "lamp"){
		set_description(light_desc);
			set_neighbor("north", light_environment);
			std::cout << "You see a new door. A huge door! oh my god. there's probably something there..." << std::endl;
		} else{
			Environment::interact(o);
		}
}
}