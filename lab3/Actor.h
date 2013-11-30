#include <iostream>

namespace lab3{
class Actor {
	std::string name;
	public:
		std::string getName () const;
		virtual std::string talkTo () const;
		std::string useItem (Item i);
	protected:
		void setName (std::string);



};
}