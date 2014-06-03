#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

namespace lab3 {

	class Environment;
	class Character;

	class Object {
	public:
		virtual ~Object() {};
		const std::string get_name() const;
		const std::string get_description() const;
		const int get_weight() const;

		virtual void use(Character &, Environment &) = 0;

	protected:
		std::string name;
		std::string description;
		int weight;
	};
}
#endif