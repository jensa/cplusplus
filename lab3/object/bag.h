#include "container.h"

namespace lab3 {

	class Bag : public Container {
		public:
			Bag();
			~Bag();
			bool use(Character &, Environment &);
	};
}