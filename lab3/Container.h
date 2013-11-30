#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <vector>
#include "Item.h"

namespace lab3 {

	class Container : public Item {
		public:
			Container(std::string, int);
			int getHoldWeight ();
			std::vector<Item> getItems ();
			void add (Item);
			void remove (Item);

		private:
			int holdWeight;
			int holdVolume;
			std::vector<Item> items;
	};
}

#endif