#include "environment.h"
namespace lab3{
class Darkroom :
	public Environment
{
public:
	Darkroom(const std::string);
	~Darkroom(void);
	void interact(const Object &);
private:
	bool lamped;
};
}

