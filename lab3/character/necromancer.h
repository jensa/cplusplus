#include "npc.h"

namespace lab3 {
	class Necromancer : public NPC {
		public:
			Necromancer(std::string name, int hp);
			const std::string talk_to(Character &, Environment &);
	};
}