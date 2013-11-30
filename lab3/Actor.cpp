#include "Actor.h"
namespace lab3{
	std::string Actor::getName () const{
		return name;
	}

	void Actor::setName (std::string n){
		name = n;
	}
}