#include<string>
#include<iostream>
#include<vector>
#include "p3.h"

  Movie::Movie(string name){
    
    this->movieName = movieName;
  }

  bool Movie::actorIn(string actor){
    
    for(int i = 0; i < actorNames.size(); i++){
      
      string a = actorNames.at(i);
      if(actor == a){
	return true;
      }
    }
    return false;
  }

 void Movie::insertActor(string actor){

      if(!actorIn(actor)){
	actorNames.push_back(actor);
	  }
  }
   

 void Movie::removeActor(string actor){

    for(int i = 0; i < actorNames.size(); i++){
      string a = actorNames[i];
      if(actor == a){
	actorNames.erase(actorNames.begin() + i);
      }
    }
  }

  string Movie::popActor(){
	string actorName;
	for(int i = 0; i < actorNames.size(); i++){
	  return  actorNames.at(i);
	}
      }

   int Movie::length(){
	int length = actorNames.size();
	return length;
      }
 
	  
int main() {
  cout << "Programming is AWESOME...\n";
  return 0;
}
      
