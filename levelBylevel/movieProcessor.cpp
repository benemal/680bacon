#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
    if (m->actorIn("Bacon, Kevin")) {
	m->actorNames.erase("Bacon, Kevin");
	while(m->actorNames.size() > 0) {
	    bacontree.AddActor(m->popActor(), m->movieName, bacontree.root);
	}
    }
    else {
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
	ProcessMovie(m);
	m = p->getNextMovie();
    }

    level = 1; it=1;
    while(level<bacontree.levelList.size()) {
	for(pos = 0; pos<unknownMovies.size(); pos++) {
	    if(unknownMovies.at(pos).isKnown == false) {
		ProcessTreesNmovies(&unknownMovies.at(pos));
	    }
	}
	level++;
	it++;
    }
    
    /*for(int q=0; q<level; q++) {
	cout << "The size of listlevel " << q << ": " <<
	bacontree.levelList.at(q).size() << endl; 
    }*/
}
 

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}

void MovieProcessor::ProcessTreesNmovies(class Movie *m) {
    TreeNode *min = NULL, *temp;
       for(set<string>::iterator i = m->actorNames.begin(); i != m->actorNames.end(); i++){
             if(bacontree.IsActorInTree(*i)) {
		 if(min == NULL){
                       min = bacontree.getTreeNode(*i);
		 }
		 else{
		     temp = bacontree.getTreeNode(*i);
		     if(min->baconNumber > temp->baconNumber) {
			 min = temp;
		     }
		 }
	     }
       }
       if(min != NULL && min->baconNumber <= it) {
           m->actorNames.erase(min->actorName);
           while(m->actorNames.size() > 0) {
                  bacontree.AddActor(m->popActor(), m->movieName, min);
           }
	   m->isKnown = true;
      }
}
