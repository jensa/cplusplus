#include "Item.h"
#include "Container.h"

namespace lab3 {
	int main () {
		Container c("Väska",10);

		Item item1("Item1",0);
		Item item2("Item2",0);
		Item item3("Item3",0);
		Item item4("Item4",0);

		c.add(item1);
		c.add(item2);
		c.add(item3);
		c.add(item4);

		std::cout << "Number of items in container: " << c.getItems().size();

		return 0;
	}
}