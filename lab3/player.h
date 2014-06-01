#include "character.h"

namespace lab3 {
	class Player : public Character {
		public:
			Player(std::string name, int hp, int mp);
			void action(Environment &);
			void fight(Character &);
		private: 
			bool go_command(std::vector<std::string>, Environment &);
			bool inventory_command();
			bool pickup_command(std::vector<std::string>, Environment &);
			bool drop_command(std::vector<std::string>, Environment &);
			bool fight_command(std::vector<std::string>, Environment &);
	};
}