#include "container.h"

namespace lab3 {

	class Bag : public Container {
		public:
			Bag();
			void use(Character &, Environment &);
	};
}