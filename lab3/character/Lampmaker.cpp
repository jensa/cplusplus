#include "lampmaker.h"

#include "../object/pocket.h"
#include "../object/key.h"
#include "../environment/environment.h"

namespace lab3 {
	
	Lampmaker::Lampmaker(std::string name_, int hp){
		type = "Lamp Maker";
		name = name_;
		hit_points = hp;
		container = new Pocket();
		go_prob = 0;
		fight_prob = 0;
		pickup_prob = 0;
		drop_prob = 0;
	}

	const std::string Lampmaker::talk_to(Character & character, Environment& env){
		Key* key = new Key();
		env.drop(*key);
		env.leave(*this);
		return "Hello. I am the lampmaker. I am of course dying. I see that you are original enough to take this lamp. Take it. just take it please. Urghhh...";
	}
}