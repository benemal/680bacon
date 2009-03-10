#include "p3.h"
#include <iostream>
#include <fstream>

using namespace std;

string query = "Input actor name: ";

int main(int argc, char **argv) {
	MovieProcessor *mp;
	string user_input;

	if(argc < 2) {
		cerr << "Usage: bacon <input file name>\n";
		return 1;
	}

	mp = new MovieProcessor(argv[1]);
	
	mp->ProcessInput();

	cout << query;
	getline(cin, user_input);

	while(!(user_input == "quit")) {
		mp->PrintBaconChain(user_input);
		cout << query;
		getline(cin, user_input);
	}

	return 0;
}
