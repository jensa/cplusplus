#include <iostream>

namespace lab3 {

	class Item {
		public:
			int getWeight ();
			int getVolume ();
			int getPrice ();

		private:
			std::string name;
			int weight;
			int volume;
			int price;
	};
}