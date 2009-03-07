#include<string>
#include<iostream>
#include<vector>
#include "p3.h"

  Movie::Movie(string name){
    this->movieName = name;
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
	actorNames.clear();
      }

   int Movie::length(){
	int length = actorNames.size();
	return length;
      }
 
void Movie::output()	{
		std::cout << movieName << endl;
		
		for(int i = 0; i < actorNames.size(); i++) {
			std::cout << actorNames[i] << endl;
		}
	}  

      
