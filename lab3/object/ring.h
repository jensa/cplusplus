#include "object.h"

namespace lab3 {

	class Ring : public Object {
		public:
			Ring();
			bool use(Character &, Environment &);
	};
}