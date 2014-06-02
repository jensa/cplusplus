#include "character.h"

namespace lab3 {
	class NPC : public Character {
		public:
			void action(Environment &);
			virtual void fight(Character &) = 0;
		protected:
			float go_prob;
			float fight_prob;
			float pickup_prob;
			float drop_prob;
	};
}