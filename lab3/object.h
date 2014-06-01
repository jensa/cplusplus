#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

namespace lab3 {

	class Environment;

	class Object {
	public:
		std::string get_name();
		int get_weight();
		int get_volume();
		int get_price();

		virtual void use(Environment &) = 0;

	protected:
		std::string name;
		int weight;
		int volume;
		int price;
	};
}
#endif