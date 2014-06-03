#include "environment.h"

namespace lab3 {
	Environment::Environment(std::string desc){
		description_string = desc;
		//neighbor_map = new std::map<std::string, Environment>();
		//objects = new std::vector<Object>();
		//characters = new std::vector<Character>();
	}

	Environment::Environment(){
		description_string = "";
	}

	std::vector<std::string> Environment::directions(){
		std::vector<std::string> directions;
		for(std::map<std::string, Environment *>::iterator iter = neighbor_map.begin(); iter != neighbor_map.end(); ++iter){
			directions.push_back(iter->first);
		}
		return directions;
	}
	
	void Environment::set_neighbor(std::string direction, Environment* neighbor){
		neighbor_map.insert(std::pair<std::string,Environment*>(direction,neighbor));
	}

	Environment* Environment::neighbor(std::string direction){
		return neighbor_map[direction];
	}
	
	std::string Environment::description() const{
		return description_string;
	}
	
	void Environment::enter(Character & c){
		characters.push_back(&c);
	}

	void Environment::leave(Character & c){
		for (std::vector<Character *>::iterator it=characters.begin();it!=characters.end();){
		    if(c.get_name() == (*(*it)).get_name()) 
		    	it = characters.erase(it);
			else 
		    	++it;
		}
	}

	void Environment::pick_up(Object & o){
		for (std::vector<Object *>::iterator it=objects.begin();it!=objects.end(); it++){
		   	if(&o == (*it)) {
		   		objects.erase(it);
		   		return;
		   	}
		}
	}

	Character& Environment::get_character(std::string name){
		std::vector<Character *>::iterator it=characters.begin();
		for (;it!=characters.end(); it++){
		   if(name == (*(*it)).get_name()) 
		      break;
		}
		return *(*it);
	}

	std::vector<std::string> Environment::get_character_names(){
		std::vector<std::string> character_names;
		for (int i = 0; i < characters.size(); i++){
			character_names.push_back((*characters[i]).get_name());
		}
		return character_names;
	}

	Object& Environment::get_object(std::string name){
		std::vector<Object *>::iterator it = objects.begin();
		for (;it!=objects.end(); it++){
		   	if(name == (*(*it)).get_name()) {
		  		break;	
		  	} 
		}
		return *(*it);
	}

	std::vector<std::string> Environment::get_object_names(){
		std::vector<std::string> object_names;
		for (int i = 0; i < objects.size(); i++){
			object_names.push_back((*objects[i]).get_name());
		}
		return object_names;
	}

	void Environment::drop(Object & o){
		objects.push_back(&o);
	}

	void Environment::interact(Object & o){
		std::cout << "Nothing happens. literally nothing." << std::endl;
	}

}

