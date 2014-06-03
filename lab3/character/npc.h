#include "character.h"

namespace lab3 {
	class NPC : public Character {
		public:
			void action(Environment &);
			void fight(Character &, Environment &);
			virtual const std::string talk_to(Character &) = 0;
		protected:
			float go_prob;
			float fight_prob;
			float pickup_prob;
			float drop_prob;
	};
}