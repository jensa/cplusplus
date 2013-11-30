#ifndef ITEM
#define ITEM
#include <iostream>

namespace lab3 {

	class Item {
		public:
			Item();
			Item(std::string, int);
			int getWeight ();
			std::string getName ();

		private:
			std::string name;
			int weight;
			int volume;
			int price;
	};
}

#endif