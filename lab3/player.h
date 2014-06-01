#include "character.h"

namespace lab3 {
	class Player : public Character {
		public:
			Player(std::string name, int hp, int mp);
			void action(Environment &);
			void fight(Character &);
	};
}