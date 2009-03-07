#include "p3.h"
#include <iostream>

void MovieProcessor::ProcessMovie(class Movie m) {
  
    
  TreeNode *min = NULL, *temp;
	for(int i = 0; i < m.actorNames.size(); i++){

	  if(baconTree.isActorInTree(m.actorNames(i)){
	    if(min == NULL){
	      min = baconTree.getTreeNode(m.actorNames(i));
	    }
	    else{
	      temp = baconTree.getTreeNode(m.actorNames(i));
	    }
	  }
	     if(temp->baconNumber < min->baconNumber){
	      min = temp;
	     }
	     }
	  if(min == NULL){
	    unknownMovies.push_back(m);
	}
	  else{
	    for(int i = 0; i < m.actorNames.size(); i++){
	      baconTree.AddActor(actorNames(i), m, min);
	    }
	  }
	
}

using namespace std;
void MovieProcessor::PrintBaconChain(string actorName) {
	class TreeNode t;

	if(!(bacontree.IsActorInTree(actorName)) {
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
}

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}
