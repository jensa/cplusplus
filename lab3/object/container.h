#ifndef CONTAINER
#define CONTAINER

#include "object.h"
#include <vector>

namespace lab3 {

	class Container : public Object {
		public:
			virtual ~Container() {};
			virtual bool use(Character &, Environment &) = 0;
			const int get_hold_weight() const;
			const int get_current_weight() const;
			bool add(Object &);
			bool remove(Object &);
			std::vector<Object *>& get_objects();
		
		protected:
			int hold_weight;
			int current_weight;
			std::vector<Object *> objects;
	};
}
#endif // !CONTAINER