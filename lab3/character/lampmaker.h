#include "npc.h"

namespace lab3 {
	class Lampmaker : public NPC {
		public:
			Lampmaker(std::string name, int hp, int dmg);
			const std::string talk_to(Character &, Environment &);
	};
}