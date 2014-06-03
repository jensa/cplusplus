#pragma once
#include "object.h"

namespace lab3{
class Key : public Object
{
public:
	Key(void);
	~Key(void);
	bool use(Character &, Environment &);
};
}
