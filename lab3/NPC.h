#include <iostream>
#include "Actor.h"

namespace lab3{
	class NPC : public Actor{
		std::string currentChat;

		public:
			std::string talkTo () const{
				return currentChat;
			}
	};
}