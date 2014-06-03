#include "environment.h"
namespace lab3{
class Darkroom :
	public Environment
{
public:
	Darkroom(const std::string, const std::string, Environment*);
	~Darkroom(void);
	void interact(const Object &);
private:
	bool lamped;
	std::string dark_desc;
	std::string light_desc;
	Environment* light_environment;
};
}

