#include "Item.h"
#include "Container.h"
#include <assert.h>

int main () {
	lab3::Container c("Väska",10);

	lab3::Item item1("Item1",2);
	lab3::Item item2("Item2",2);
	lab3::Item item3("Item3",3);
	lab3::Item item4("Item4",3);
	lab3::Item item5("Item5",2);

	assert(c.add(item1) == true);
	assert(c.getCurrentWeight() == 2);
	assert(c.add(item2) == true);
	assert(c.getCurrentWeight() == 4);
	assert(c.add(item3) == true);
	assert(c.getCurrentWeight() == 7);
	assert(c.add(item4) == true);
	assert(c.getCurrentWeight() == 10);
	assert(c.add(item5) == false);
	assert(c.getCurrentWeight() == 10);

	assert(c.getItems().size() == 4);
	
	assert(c.remove(item4) == true);

	assert(c.getItems().size() == 3);
	assert(c.remove(item4) == false);

	return 0;
}	