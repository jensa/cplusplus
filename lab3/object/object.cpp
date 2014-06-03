#include "object.h"

namespace lab3 {

	const std::string Object::get_name() const{
		return name;
	}

	const std::string Object::get_description() const{
		return description;
	}

	const int Object::get_weight() const{
		return weight;
	}
}