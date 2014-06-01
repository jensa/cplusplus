#include "character.h"

namespace lab3 {
	class NPC : public Character {
		public:
			void action();
			virtual void fight(Character &) = 0;
	};
}