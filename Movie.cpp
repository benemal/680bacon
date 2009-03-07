#include<string>
#include<iostream>
#include<vector>
#include "p3.h"

  Movie::Movie(string name){
    this->movieName = name;
  }

  bool Movie::actorIn(string actor){
    return (actorNames.count(actor) == 1);
  }

 void Movie::insertActor(string actor){
 	actorNames.insert(actor);
  }
   

 void Movie::removeActor(string actor){
 	actorNames.erase(actor);
 }

  string Movie::popActor(){
	string result;
	result = *actorNames.begin();
	actorNames.erase(result);
	return result;
  }
 

