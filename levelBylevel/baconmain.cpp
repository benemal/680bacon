/*	bacon - relates actors to Kevin Bacon given an input file of movies
 *
 *	Arguments:
 *		filename of input containing a list of movies
 *
 *	Behavior:
 *		assuming correct input, bacon will process it and then await user input.
 *		Until the user types "quit" or otherwise terminates the program,
 *		bacon will output the relationship of the given actor to Kevin Bacon.
 *
 */
#include "p3.h"
#include <iostream>
#include <fstream>

using namespace std;

string query = "Input actor name: ";
string usage = "Usage: bacon <input file name>\n";
string quitcommand = "quit";

int main(int argc, char **argv) {
	MovieProcessor *mp;		// Processor used to process input
	string user_input;		// input from user

	if(argc < 2) {		// user MUST provide an input file
		cerr << usage;
		return 1;
	}

	mp = new MovieProcessor(argv[1]);
	
	mp->ProcessInput();

	cout << query;
	getline(cin, user_input);

	while(!(user_input == quitcommand)) {
		mp->PrintBaconChain(user_input);
		cout << query;
		getline(cin, user_input);
	}

	return 0;
}
