#include "character.h"

namespace lab3 {
	class NPC : public Character {
		public:
			void action(Environment &);
			virtual void fight(Character &) = 0;
	};
}