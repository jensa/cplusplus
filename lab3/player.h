#ifndef PLAYER
#define PLAYER
#include "character.h"

namespace lab3 {
	class Player : public Character {
		public:
			Player(std::string name, int hp, int mp);
	};
}
#endif