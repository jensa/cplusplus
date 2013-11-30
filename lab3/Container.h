#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <vector>
#include "Item.h"

namespace lab3 {

	class Container : public Item {
		public:
			Container();
			Container(std::string, int);
			int getHoldWeight ();
			int getCurrentWeight ();
			std::vector<Item> getItems();
			bool add (Item);
			bool remove (Item);

		private:
			int holdWeight;
			int currentWeight;
			std::vector<Item> items;
	};
}

#endif