#include <iostream>
#include <vector>
#include "environment.h"

namespace lab3 {
	//std::vector<Item> items;
	std::map <std::string, Environment> neighbor_map;
	std::vector<std::string> neighbors;
	std::string description;

	Environment::Environment(std::string desc){
		description = desc;
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
		return neighbor_map[direction];
	}
	
	std::string Environment::description() const{
		return description;
	}
	
	void Enviroment::enter(Character c){

	}

	void Environment::leave(Character c){

	}

	void Environment::pick_up(Object o){

	}

	void Environment::drop(Object o){

	}

}

