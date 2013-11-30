#include "Container.h"

namespace lab3 {

	Container::Container() {

	}

	Container::Container(std::string name, int holdWeight) : Item(name,0) {
		this -> holdWeight = holdWeight;
	}

	int Container::getHoldWeight () {
		return holdWeight;
	}

	int Container::getCurrentWeight () {
		return currentWeight;
	}

	std::vector<Item> Container::getItems () {
		return items;
	}

	bool Container::add (Item i) {
		if (currentWeight + i.getWeight() <= holdWeight) {
			items.push_back(i);
			currentWeight += i.getWeight();
			return true;
		} else {
			return false;
		}
	}

	bool Container::remove (Item i) {
		for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
  			if ((*it).getName() == i.getName()) {
  				items.erase(it);
  				return true;
  			}
		}
		return false;
	}
}