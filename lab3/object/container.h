#include "object.h"
#include <vector>

namespace lab3 {

	class Container : public Object {
		public:
			virtual void use(Character &, Environment &) = 0;
			int get_hold_weight();
			int get_current_weight();
			bool add(Object &);
			bool remove(Object &);
			std::vector<Object *>& get_objects();
		
		protected:
			int hold_weight;
			int current_weight;
			std::vector<Object *> objects;
	};
}