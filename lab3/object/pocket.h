#include "container.h"

namespace lab3 {

	class Pocket : public Container {
		public:
			Pocket();
			void use(Character &, Environment &);
	};
}