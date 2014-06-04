#include "container.h"

namespace lab3 {

	const int Container::get_hold_weight() const{
		return hold_weight;
	}

	const int Container::get_current_weight() const{
		return current_weight;
	}

	bool Container::add(Object& o){
		int object_weight = o.get_weight();
		if ((current_weight+object_weight) <= hold_weight){
			objects.push_back(&o);
			current_weight += object_weight;
			return true;
		} else {
			return false;
		}
	}

	bool Container::remove(Object& o){
		int object_weight = o.get_weight();
		for (std::vector<Object *>::iterator it=objects.begin();it!=objects.end(); it++){
		   	if(&o == (*it)){
		   		objects.erase(it);
		   		current_weight -= object_weight;
		   		return true;
		   	}
		}
		return false;
	}

	std::vector<Object *>& Container::get_objects(){
		return objects;
	}
}