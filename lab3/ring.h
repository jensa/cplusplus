#include "object.h"

namespace lab3 {

	class Ring : public Object {
		public:
			Ring(std::string name);
			void use(Environment &);
	};
}