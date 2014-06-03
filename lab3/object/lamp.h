#pragma once
#include "object.h"

namespace lab3{
class Lamp :public Object
{
public:
	Lamp(void);
	~Lamp(void);
	void use(Character &, Environment &);
};
}

