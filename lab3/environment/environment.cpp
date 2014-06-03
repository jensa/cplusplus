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

	const std::vector<std::string> Environment::directions() const{
		std::vector<std::string> directions;
		for(std::map<std::string, Environment *>::const_iterator iter = neighbor_map.begin(); iter != neighbor_map.end(); ++iter){
			directions.push_back(iter->first);
		}
		return directions;
	}
	
	void Environment::set_neighbor(const std::string direction, Environment* neighbor){
		neighbor_map.insert(std::pair<std::string,Environment*>(direction,neighbor));
	}

	Environment* Environment::neighbor(const std::string direction) {
		return neighbor_map[direction];
	}
	
	const std::string Environment::description() const{
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

	Character* Environment::get_character(const std::string name) const{
		std::vector<Character *>::const_iterator it=characters.begin();
		for (;it!=characters.end(); it++){
		   if(name == (*(*it)).get_name()) 
		      return *it;
		}
		return NULL;
	}

	Character* Environment::get_player() const{
		for (std::vector<Character *>::const_iterator it=characters.begin();it!=characters.end(); it++){
		   if("Player" == (*(*it)).get_type()) 
		      	return *it;
		}
		return NULL;
	}

	const std::vector<std::string> Environment::get_character_names() const{
		std::vector<std::string> character_names;
		for (int i = 0; i < characters.size(); i++){
			character_names.push_back((*characters[i]).get_name());
		}
		return character_names;
	}

	Object* Environment::get_object(const std::string name) const{
		std::vector<Object *>::const_iterator it = objects.begin();
		for (;it!=objects.end(); it++){
		   	if(name == (*(*it)).get_name()) {
		  		return *it;	
		  	} 
		}
		return NULL;
	}

	const std::vector<std::string> Environment::get_object_names() const{
		std::vector<std::string> object_names;
		for (int i = 0; i < objects.size(); i++){
			object_names.push_back((*objects[i]).get_name());
		}
		return object_names;
	}

	void Environment::drop(Object & o){
		objects.push_back(&o);
	}

	void Environment::interact(const Object & o){
		std::cout << "Nothing happens. literally nothing." << std::endl;
	}

	void Environment::set_description(std::string new_desc){
		description_string = new_desc;
	}

}

