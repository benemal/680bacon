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
     //it = inputFile.begin();
}

void Parser::RestartInput(string inputFile) {
     inputstream->close();
     inputstream = new ifstream(inputFile.c_str());
    
    if (!inputstream)
     {
         cerr << "Uh oh, input file could not be opened for reading!" << endl;
     }
}

class Movie* Parser::getNextMovie() {
    char* pch; char* line4;
    string line,movieName,temp;
    class Movie *m;

    if (!inputstream->eof())  
    {
         getline(*inputstream,line);
    }
    
    size_t length; int a = line.length();

    line4 = new char [line.size()+1];
    strcpy(line4,line.c_str());
    pch = strtok (line4, "/");
    int i=0;
    if(pch == NULL)
	return NULL;
    while(pch != NULL)
    {
	if(i==0) {
	    movieName = pch;
	    m = new Movie(movieName);
	    //cout << "in parser :" << m->movieName << endl;
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

    
