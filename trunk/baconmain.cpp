#include "p3.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	MovieProcessor *mp;
	string user_input;

	if(argc < 2) {
		cerr << "Usage: bacon <input file name>\n";
		return 1;
	}

	mp = new MovieProcessor(argv[1]);

	mp->ProcessInput();

	cin >> user_input;

	while(!(user_input == "quit")) {
		mp->PrintBaconChain(user_input);
	}

	return 0;
}
