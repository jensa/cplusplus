#include "npc.h"

namespace lab3 {
	class Troll : public NPC {
		public:
			Troll(std::string, int, int);
			void action();
			void fight(Character&);
			void talk_to(Character&);
	};
}