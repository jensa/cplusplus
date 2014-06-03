#pragma once
#include "environment.h"
namespace lab3{
class Lockedroom : public Environment
{
public:
	Lockedroom(void);
	Lockedroom(std::string, std::string, Environment*);
	~Lockedroom(void);
	void interact(const Object &);
private:
	Environment* unlocked_neighbor;
	std::string open_description;
};
}
