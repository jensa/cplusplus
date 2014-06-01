#include "environment.h"

namespace lab3 {
	Environment::Environment(std::string desc){
		description_string = desc;
		//neighbor_map = new std::map<std::string, Environment>();
		//items = new std::vector<Object>();
		//characters = new std::vector<Character>();
	}

	Environment::Environment(){
		description_string = "";
	}

	std::string Environment::directions(){
		std::string toReturn = "";
		for(std::map<std::string, Environment *>::iterator iter = neighbor_map.begin(); iter != neighbor_map.end(); ++iter){
			toReturn += iter->first;
		}
		return toReturn;
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
		for (std::vector<Object *>::iterator it=items.begin();it!=items.end(); it++){
		   	if(&o == (*it)) {
		   		items.erase(it);
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

	Object* Environment::getObject(std::string name){
		for (std::vector<Object *>::iterator it=items.begin();it!=items.end(); it++){
		   	if(name == (*(*it)).get_name()) {
		  		return *it;
		  	} 
		}
		return NULL;
	}

	std::vector<Object *> Environment::getObjects(){
		return items;
	}

	void Environment::drop(Object & o){
		items.push_back(&o);
	}

}

