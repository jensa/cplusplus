#ifndef NPC_H
#define NPC_H

#include "character.h"

namespace lab3 {
	class NPC : public Character {
		public:
			virtual ~NPC() {};
			bool action(Environment &);
			void fight(Character &, Environment &);
			virtual const std::string talk_to(Character &, Environment &) = 0;
		protected:
			float go_prob;
			float fight_prob;
			float pickup_prob;
			float drop_prob;
	};
}
#endif