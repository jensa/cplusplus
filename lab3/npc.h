#include "character.h"
#include <iostream>

namespace lab3 {
	class NPC : public Character {
		public:
			virtual void action() = 0;
			virtual void fight(Character&) = 0;
			virtual void talk_to(Character&) = 0;
	};
}