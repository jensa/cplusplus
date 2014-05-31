#include <iostream>
#include <vector>

namespace lab3 {
	//std::vector<Item> items;
	std::vector<std::string> neighbors;

	Environment::Environment(){
		//items = new std::vector<Item>();
	}

	std::string Encironment::directions(){
		std::string toReturn = "possible directions are: "
		for (std::vector<std::string>::iterator i = neighbors.begin(); i != neighbors.end(); ++i)
		{
			toReturn += i;
		}
		return toReturn;
	}

}

