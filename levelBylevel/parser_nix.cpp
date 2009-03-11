#include <stdio.h>
#include <iostream>
#include <fstream>
#include "p3.h"

using namespace std;

Parser::Parser(string inputFile) {
    inputstream = new ifstream(inputFile.c_str());
    if (!inputstream)
     {
         cerr << "Uh oh, input file could not be opened for reading!" << endl;
     }
}

class Movie* Parser::getNextMovie() {
    // Reads one 'Movie' object at a time from the input file.
    char* pch; char* charLine;
    string line,movieName,temp;
    class Movie *m;
    int i=0;

    if (!inputstream->eof())  
    {
         getline(*inputstream,line);
    }
    
    charLine = new char [line.size()+1];
    strcpy(charLine,line.c_str());
    pch = strtok (charLine, "/");

    //Returns NULL, if at the end of the input file.
    if(pch == NULL)
	return NULL;

    while(pch != NULL)
    {
	if(i==0) {
	    movieName = pch;
	    m = new Movie(movieName);
	}
	if(i!=0) {
	    m->insertActor(pch);
	}
	pch = strtok (NULL, "/");
	i++;
    }
    m->isKnown = false;
    return m;
}

    
