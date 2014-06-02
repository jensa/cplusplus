#include "object.h"

namespace lab3 {

	class Ring : public Object {
		public:
			Ring();
			void use(Character &, Environment &);
	};
}