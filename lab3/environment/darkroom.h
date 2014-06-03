#include "environment.h"
namespace lab3{
class Darkroom :
	public Environment
{
public:
	Darkroom(void);
	~Darkroom(void);
	void interact(Object &);
private:
	bool lamped;
};
}

