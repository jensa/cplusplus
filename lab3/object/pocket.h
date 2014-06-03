#include "container.h"

namespace lab3 {

	class Pocket : public Container {
		public:
			Pocket();
			~Pocket();
			bool use(Character &, Environment &);
	};
}