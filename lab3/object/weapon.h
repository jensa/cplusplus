#pragma once
#include "object.h"

namespace lab3{
class Weapon :
	public Object
{
public:

	Weapon(void);
	~Weapon(void);
	Weapon(int damage, int weight, std::string, std::string);
	int get_damage();

private:
	int damage;
};
}
