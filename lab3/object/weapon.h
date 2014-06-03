#pragma once
#include "object.h"

namespace lab3{
class Weapon :
	public Object
{
public:

	Weapon(void);
	Weapon(int damage, int weight, std::string, std::string);
	int get_damage();
	bool use(Character &, Environment &);

private:
	int damage;
};
}
