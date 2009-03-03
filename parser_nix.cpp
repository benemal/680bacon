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

class Movie* Parser:: getNextMovie() {
    string line,movieName; 
    if (!inputstream->eof())  
    {
         getline(*inputstream,line);
    }

    //movieName = 
    class Movie *m = new Movie(line);
    return m;
}

int main() {
    cout << "Hello frm main()\n";
    class Parser p = Parser("input.txt");
    class Movie *m1;
    m1 = p.getNextMovie();
    cout << m1->movieName;
    
    return 0;
}
    
