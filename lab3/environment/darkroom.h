#include "environment.h"
namespace lab3{
class Darkroom :
	public Environment
{
public:
	Darkroom(std::string);
	~Darkroom(void);
	void interact(Object &);
private:
	bool lamped;
};
}

