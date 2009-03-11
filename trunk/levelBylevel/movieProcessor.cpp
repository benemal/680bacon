#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
    // This method finds all movies with "Bacon, Kevin" and adds them
    // to the bacon tree.
    // The rest of them will be added to 'unknownMovies' vector.
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
    // This method prints the connection between the input actor and
    // "Bacon, Kevin".
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
    int level=0;
    
    //For every movie read from the input file, processMovie() will be
    //called.
    m=p->getNextMovie();
    while (m != NULL) {
	ProcessMovie(m);
	m = p->getNextMovie();
    }
    
    //For every unknown movie ('isKnown' == false) in the 'unknownMovies' vector,
    //ProcessTreesNmovies() will be called
    level = 1; it=1;
    while(level<bacontree.levelList.size()) {
	for(int pos = 0; pos<unknownMovies.size(); pos++) {
	    if(unknownMovies.at(pos).isKnown == false) {
		ProcessTreesNmovies(&unknownMovies.at(pos));
	    }
	}
	level++;
	it++;
    }
    
    for(int q=0; q<level; q++) {
	cout << "Number of actors at bacon level " << q << ": " << bacontree.levelList.at(q).size() << endl;  
    }
}


MovieProcessor::MovieProcessor(string inputFile) {
    p = new Parser(inputFile);
}

void MovieProcessor::ProcessTreesNmovies(class Movie *m) {
    //This method finds an actor in the given movie with the minimum
    //baconNumber in the 'bacontree' (which is a 'node') and add
    //rest of the actors of that movie to that tree node.
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
