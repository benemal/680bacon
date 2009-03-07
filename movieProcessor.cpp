#include <iostream>
#include <vector>
#include "p3.h"
#include <iostream>

using namespace std;

void MovieProcessor::ProcessMovie(class Movie *m) {
    TreeNode *min = NULL, *temp;
    for(int i = 0; i < m->actorNames.size(); i++){
	if(bacontree.IsActorInTree(m->actorNames[i])) {
	    if(min == NULL){
		min = bacontree.getTreeNode(m->actorNames[i]);
	    }
	    else{
	      temp = bacontree.getTreeNode(m->actorNames[i]);
	    }
	    if(temp->baconNumber < min->baconNumber){
		min = temp;
	    }
      }
    }
    if(min == NULL){
      unknownMovies.push_back(*m);
      /*for (int i=0; i<unknownMovies.size(); i++) {
	  cout << unknownMovies[i].movieName << endl;
      }*/
    }
    else{
	for(int i = 0; i < m->actorNames.size(); i++){
	    if(m->actorNames[i] != "Bacon, Kevin"){
		bacontree.AddActor(m->actorNames[i], m->movieName, min);
		cout << m->actorNames[i] << " || " << m->movieName << " || "
		     << min->actorName << " || " << min->baconNumber << endl;
	    }
	}
	cout << "==========================================================\n";
    }
}

using namespace std;
void MovieProcessor::PrintBaconChain(string actorName) {
	class TreeNode *t;

	if(!(bacontree.IsActorInTree(actorName))) {
		cerr << actorName << " is not on the list.\n";
		return;
	}

	t = bacontree.getTreeNode(actorName);

	while( t->parent != NULL ) {
		cout << t->actorName << "was in " << t->movieName << " with " << t->parent->actorName;
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
}
 

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}
