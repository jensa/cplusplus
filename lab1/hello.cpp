#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
	if (argc < 2){
		cout << "Hello World";
	} else {
		string name ("");
		int num = atoi (argv[1]);
		if (num == 0){
			name = string (argv[1]);
			string zero ("0");
			if (zero.compare(name) == 0){
				name = "";
			}
			cout << "Hello " << name;
		} else{
			if (argv[2] == NULL)
				name = string("World");
			else
				name = string (argv[2]);
			cout << "Hello ";
			for (int i = 0; i < num-1; ++i)
			{
				cout << name << " ";
			}
			cout << name;
		}
	}
	cout << "!\n";
}