#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
	bool unknownMovie = true;
	for(int i = 0; i < bacontree.levelList.size(); i++) {
		for(int j = 0; j < bacontree.levelList.at(i).size(); j++) {
			if(m->actorIn(bacontree.levelList.at(i).at(j)->actorName)) {
				unknownMovie = false;
				m->removeActor(bacontree.levelList.at(i).at(j)->actorName);
				while(m->actorNames.size() > 0) {
					bacontree.AddActor(m->popActor(), m->movieName, bacontree.levelList.at(i).at(j));
				}
			}
		}
	}
			
    if(unknownMovie){
      unknownMovies.push_back(*m);
    }
}

void MovieProcessor::PrintBaconChain(string actorName) {
	class TreeNode *t;

	if(!(bacontree.IsActorInTree(actorName))) {
		cerr << actorName << " is not on the list.\n";
		return;
	}

	t = bacontree.getTreeNode(actorName);

	cout << t->actorName << " has a bacon number of " << t->baconNumber << endl;
	while( t->parent != NULL ) {
		cout << t->actorName << " was in " << t->movieName
		     << " with " << t->parent->actorName << endl;
		t = t->parent;
	}
}

void MovieProcessor::ProcessInput() {
    class Movie *m;

    m=p->getNextMovie();
    while (m != NULL) {
	//cout << m->movieName << "=====================================\n";
	//for(int i=0; i<m->actorNames.size(); i++)
	    //cout << m->actorNames[i] << endl;
	ProcessMovie(m);
	m = p->getNextMovie();
    }

	for(int i = 0; i < bacontree.levelList.size(); i++) {
		for(int j = 0; j < bacontree.levelList.at(i).size(); j++) {
			for(int k = 0; k < unknownMovies.size(); k++) {
				// is the actor at levelList[i][j] in the movie?
				if(unknownMovies.at(k).actorIn(bacontree.levelList.at(i).at(j)->actorName)) {
					unknownMovies.at(k).removeActor(bacontree.levelList.at(i).at(j)->actorName);
					while(unknownMovies.at(k).actorNames.size() > 0) {
						bacontree.AddActor(unknownMovies.at(k).popActor(), unknownMovies.at(k).movieName, bacontree.levelList.at(i).at(j));
					}
	
					unknownMovies.erase(unknownMovies.begin()+k);
					k--;
				}
			}
		}
	}

	PrintHeadCount();
}
 

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}

void MovieProcessor::PrintHeadCount() {
	cout << "Bacon Number\tFrequency" << endl;
	cout << "------------------------" << endl;

	for(int i = 0; i < bacontree.levelList.size(); i++) {
		cout << "\t\t" << i << "\t\t\t" << bacontree.levelList.at(i).size() << endl;
	}
}
