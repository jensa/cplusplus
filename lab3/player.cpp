#include "player.h"

namespace lab3 {

	Player::Player(std::string name, int hp, int mp) {
		type = "Player";
		name = name;
		hit_points = hp;
		mana_points = mp;
	}
}