#include "../character/character.h"

namespace lab3 {
	class Player : public Character {
		public:
			~Player();
			Player(std::string name, int hp);
			bool action(Environment &);
			void fight(Character &, Environment &);
			const std::string talk_to(Character &, Environment &);
			const void print_help() const;
		private: 
			bool go_command(const std::vector<std::string>, Environment &);
			void inventory_command() const;
			bool pickup_command(const std::vector<std::string>, Environment &);
			bool drop_command(const std::vector<std::string>, Environment &);
			int use_command(const std::vector<std::string> tokens, Environment & env);
			void examine_command(const std::vector<std::string> tokens) const;
			void look_command(const Environment & env) const;
			void directions_command(const Environment & env) const;
			bool fight_command(const std::vector<std::string>, Environment &);
			bool talk_command(const std::vector<std::string>, Environment &);
	};
}