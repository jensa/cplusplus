#include "npc.h"

#include <iostream>

namespace lab3 {

	void NPC::action() {

		float r = ((float) rand() / (RAND_MAX));

		if (r < 0.20) {
			//GO
		} else if (r < 0.40) {
			//FIGHT
		} else if (r < 0.60) {
			//PICK UP
		} else if (r < 0.80) {
			//DROP
		} else {
			//TALK TO
		}
	}
}