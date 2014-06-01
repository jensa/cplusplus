#include "object.h"

namespace lab3 {

std::string Object::get_name(){
	return name;
}

int Object::get_weight(){
	return weight;
}

int Object::get_volume(){
	return volume;
}

int Object::get_price(){
	return price;
}

}