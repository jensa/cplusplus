#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

namespace lab3 {

	class Object {
	public:
		int get_name();
		int get_weight();
		int get_volume();
		int get_price();

	private:
		std::string name;
		int weight;
		int volume;
		int price;
	};
}
#endif