#include "npc.h"

namespace lab3 {
	class Troll : public NPC {
		public:
			Troll(std::string name, int hp);
			const std::string talk_to(Character &);
	};
}