#include "Container.h"

namespace lab3 {

	Container::Container(std::string name, int holdWeight) : Item(name,0) {
		this -> holdWeight = holdWeight;
	}

	int Container::getHoldWeight () {
		return holdWeight;
	}

	std::vector<Item> Container::getItems () {
		return items;
	}

	void Container::add (Item i) {
		items.push_back(i);
	}

	void Container::remove (Item i) {
		for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
  			if ((*it).getName() == i.getName()) {
  				items.erase(it);
  				break;
  			}
		}
	}
}