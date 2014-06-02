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

	Character* Environment::getCharacter(std::string name){
		for (std::vector<Character *>::iterator it=characters.begin();it!=characters.end(); it++){
		   if(name == (*(*it)).get_name()) 
		      return *it;
		}
		return NULL;
	}

	std::vector<Character *> Environment::getCharacters(){
		return characters;
	}

	Object& Environment::getObject(std::string name){
		std::vector<Object *>::iterator it = objects.begin();
		for (;it!=objects.end(); it++){
		   	if(name == (*(*it)).get_name()) {
		  		break;	
		  	} 
		}
		return *(*it);
	}

	std::vector<Object *> Environment::getObjects(){
		return objects;
	}

	void Environment::drop(Object & o){
		objects.push_back(&o);
	}

}

