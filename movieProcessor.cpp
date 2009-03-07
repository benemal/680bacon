#include "p3.h"

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
      
	     
	     
	      
		  
		  
	       
	       
	    
	    
	    
	  


void MovieProcessor::ProcessInput() {
}

MovieProcessor::MovieProcessor(string inputFile) {
	p = new Parser(inputFile);
}
