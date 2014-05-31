#include "environment.h"

namespace lab3 {
	//std::vector<Item> items;
	

	Environment::Environment(std::string desc){
		description_string = desc;
		//items = new std::vector<Item>();
	}

	std::string Environment::directions(){
		std::string toReturn = "possible directions are: ";
		for (std::vector<std::string>::iterator i = neighbors.begin(); i != neighbors.end(); ++i)
		{
			toReturn += *i;
		}
		return toReturn;
	}

	Environment Environment::neighbor(std::string direction){
		//return neighbor_map[""];
		return Environment(std::string(""));
	}
	
	std::string Environment::description() const{
		return description_string;
	}
	
	void Environment::enter(Character & c){

	}

	void Environment::leave(Character & c){

	}

	void Environment::pick_up(Object & o){

	}

	void Environment::drop(Object & o){

	}

}

