#pragma once
#include "object.h"

namespace lab3{
class Pointeritem :public Object {
public:
	Pointeritem(void);
	~Pointeritem(void);

	void use(Character &, Environment &);
};
}