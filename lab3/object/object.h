#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

namespace lab3 {

	class Environment;
	class Character;

	class Object {
	public:
		std::string get_name();
		std::string get_description();
		int get_weight();

		virtual void use(Character &, Environment &) = 0;

	protected:
		std::string name;
		std::string description;
		int weight;
	};
}
#endif