#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
    /*TreeNode *min = NULL, *temp;
    for(set<string>::iterator i = m->actorNames.begin(); i != m->actorNames.end(); i++){
		if(bacontree.IsActorInTree(*i)) {
		    if(min == NULL){
				min = bacontree.getTreeNode(*i);
		    }
		    else{
		      temp = bacontree.getTreeNode(*i);
			    if(temp->baconNumber < min->baconNumber){
					min = temp;
			    }
			}
		}
    }
    if(min == NULL){
      unknownMovies.push_back(*m);
    }
    else{
		m->actorNames.erase(min->actorName);

		while(m->actorNames.size() > 0) {
			bacontree.AddActor(m->popActor(), m->movieName, min);
		}
    }*/
    if (m->actorIn("Bacon, Kevin")) {
	m->actorNames.erase("Bacon, Kevin");
	while(m->actorNames.size() > 0) {
	    bacontree.AddActor(m->popActor(), m->movieName, bacontree.root);
	}
    }
    else {
	unknownMovies.push_back(*m); //should uncomment this line.....nix
    }
}

void MovieProcessor::PrintBaconChain(string actorName) {
	class TreeNode *t;

	if(!(bacontree.IsActorInTree(actorName))) {
		cerr << actorName << " is not on the list.\n";
		return;
	}

	t = bacontree.getTreeNode(actorName);

	while( t->parent != NULL ) {
		cout << t->actorName << " was in " << t->movieName
		     << " with " << t->parent->actorName << endl;
		t = t->parent;
	}
}

void MovieProcessor::ProcessInput() {
    class Movie *m;
    int level=0;

    m=p->getNextMovie();
    while (m != NULL) {
	//cout << m->movieName << "=====================================\n";
	//for(int i=0; i<m->actorNames.size(); i++)
	    //cout << m->actorNames[i] << endl;
	ProcessMovie(m);
	m = p->getNextMovie();
    }

    //run for second time to get values in level2
    //p->RestartInput("movies-mpaa.txt");
    /*m=p->getNextMovie();
    cout << m->movieName << "=====================================\n";
    while (m != NULL) {
	//cout << m->movieName << "=====================================\n";
	//for(int i=0; i<m->actorNames.size(); i++)
	    //cout << m->actorNames[i] << endl;
	ProcessTreesNmovies(m);
	m = p->getNextMovie();
    }*/

    level = 1;
    //atEnd = false;
    int it=0;
    while(it<15) {
	for(int pos = 0; pos<unknownMovies.size(); pos++) {
	    m = &unknownMovies[pos];
	    if(m->isKnown == false) {
		ProcessTreesNmovies(m);
	    }
	}
	level++;
	it++;
    }

    
    for(int q=0; q<level; q++) {
	cout << "The size of listlevel " << q << ": " << bacontree.levelList.at(q).size() << endl;
    }
    
    /*cout << "Before loop: UnknownMovies.Size() = " << unknownMovies.size() << "\nThe size of listlevel 1: " << bacontree.levelList.at(1).size() << "\nThe size of listlevel 2: " << bacontree.levelList.at(2).size() << endl;
    int i=0;*/
	/*for(i = 1; i < bacontree.levelList.size(); i++) {
		for(int j = 0; j < bacontree.levelList.at(i).size(); j++) {
			for(int k = 0; k < 7000; k++) {
				//is the actor at levelList[i][j] in
				//the movie?
 if(unknownMovies.at(k).isKnown == false) {
				if(unknownMovies.at(k).actorIn(bacontree.levelList.at(i).at(j)->actorName)) {
					unknownMovies.at(k).removeActor(bacontree.levelList.at(i).at(j)->actorName);
					while(unknownMovies.at(k).actorNames.size() > 0) {
						bacontree.AddActor(unknownMovies.at(k).popActor(), unknownMovies.at(k).movieName, bacontree.levelList.at(i).at(j));
					}
	
					//unknownMovies.erase(unknownMovies.begin()+k);
					unknownMovies.at(k).isKnown = true;
					k--;
				}
 }
			}
		}
	}
	cout << "After loop: UnknownMovies.Size() = " <<
	unknownMovies.size() << "\nThe size of listlevel " << i-1 <<
	": " << bacontree.levelList.at(i-1).size() << endl; */
}
 

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}

void MovieProcessor::ProcessTreesNmovies(class Movie *m) {
       TreeNode *min = NULL, *temp, *temp1;
       for(set<string>::iterator i = m->actorNames.begin(); i != m->actorNames.end(); i++){
             if(bacontree.IsActorInTree(*i)) {
                  if(min == NULL){
                       min = bacontree.getTreeNode(*i);
		       /*if(temp1->baconNumber == level) {
			   min = temp1;
		       }*/
                  }
                  /*else{
                       temp1 = bacontree.getTreeNode(*i);
		       if(temp1->baconNumber == level) {
			   temp = temp1;
		       }
		       if(temp != NULL) {
			   if(temp->baconNumber < min->baconNumber){
			       min = temp;
			   }
                      }
                 }*/
            }
       }
       if(min == NULL){
	   //unknownMovies.push_back(*m);
	   //atEnd = true;
       }
       else{
           m->actorNames.erase(min->actorName);
           while(m->actorNames.size() > 0) {
                  bacontree.AddActor(m->popActor(), m->movieName, min);
           }
	   m->isKnown = true;
      }
}
