#include "object.h"

namespace lab3 {

	std::string Object::get_name(){
		return name;
	}

	std::string Object::get_description(){
		return description;
	}

	int Object::get_weight(){
		return weight;
	}
}