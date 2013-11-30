#include "Item.h"

namespace lab3 {

	Item::Item() {
	}

	Item::Item(std::string name, int weight) {
		this -> name = name;
		this -> weight = weight;
	}
	
	std::string Item::getName () {
		return name;
	}

	int Item::getWeight () {
		return weight;
	}
}