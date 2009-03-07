#include "p3.h"

using namespace std;

int main(int argc, char **argv) {
	MovieProcessor *mp;
	string user_input;

	if(argc < 2) {
		stderr << "Usage: bacon <input file name>\n";
		return 1;
	}

	mp = new MovieProcessor(argv[1]);

	mp->ProcessInput();

	stdin >> user_input;

	while(!(user_input == "quit")) {
		PrintBaconChain(user_input);
	}

	return 0;
}
