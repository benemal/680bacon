#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
    TreeNode *min = NULL, *temp;
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
}
 

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}
