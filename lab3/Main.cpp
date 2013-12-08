#include "Main.h"

int main (){
	initializeGame ();
	bool running = true;
	while (running){
		writeWorld ();
		std::string input = getInput ();
		if (input == "quit")
			running = false;
		parseInput (input);
	}
	exit (0);
}
