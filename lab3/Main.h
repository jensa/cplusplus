#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void initializeGame (){
}

std::string getInput (){
	std::string input;
	std::getline (std::cin, input);
	return input;
}

/**
 * Outputs the state of the game.
 * Writes a description of the world
 * and action options
 */
void writeWorld (){
}

std::vector<std::string> splitString (const std::string & toSplit, const std::string & delim){
	size_t start = 0;
	size_t end = 0;
	std::vector<std::string> result;
	while (end != std::string::npos){
		end = toSplit.find (delim, start);
		size_t numChars = end - start;
		if (end == std::string::npos)
			numChars = std::string::npos;
		std::string token = toSplit.substr( start, numChars);
		result.push_back (token);
		start = end + delim.size ();
	}

	return result;
}


/**
 * Reads input and performs actions based on it.
 */
void parseInput (std::string input){
	std::vector<std::string> tokens = splitString (input, " ");
	for (int i=0;i<tokens.size ();i++){
		std::cout << "token " << i << " : " << tokens[i];
	}
}

