#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

namespace lab3 {

	class Environment;
	class Character;

	class Object {
	public:
		std::string get_name();
		int get_weight();

		virtual void use(Character &, Environment &) = 0;

	protected:
		std::string name;
		int weight;
	};
}
#endif