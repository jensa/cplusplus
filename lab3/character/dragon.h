#pragma once
#include "npc.h"

namespace lab3{
class Dragon : public NPC
{
public:
	Dragon(void);
	~Dragon(void);
	Dragon(std::string, int, Weapon*);
	const std::string talk_to(Character &, Environment &);
};
}

