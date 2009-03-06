#include <stdio.h>
#include <iostream.h>
#include <fstream>
#include "p3.h"

using namespace std;

Parser::Parser(string inputFile) {
    inputstream = new ifstream(inputFile.c_str());

    if (!inputstream)
     {
         cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
     }
    
     /*while (!inputstream->eof())  
     {
         string strInput;  
         getline(*inputstream,strInput); 
         cout << strInput << endl;  
     }
     inputstream->close();*/
}

class Movie* Parser::getNextMovie() {
    char* pch; char* line4;
    string line,movieName,temp;
    vector<string> actorNames;
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
    while(pch != NULL)
    {
	if(i==0) {
	    movieName = pch;
	    m = new Movie(movieName);
	    cout << m->movieName << endl;
	}
	if(i!=0) {
	    m->insertActor(pch);
	}
	pch = strtok (NULL, "/");
	i++;
    }

    /*cout << "actor names are:\n";
    for(i=0; i<actorNames.size(); i++)
	cout << actorNames[i] << endl;*/
    //class Movie *m = new Movie(line);
    //m->actorNames = actorNames;
    return m;
}

    
