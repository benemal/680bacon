#include<string>
#include<iostream>
#include<vector>
#include "p3.h"

Movie::Movie(string name){
    this->movieName = name;
}

bool Movie::actorIn(string actor){
    // Returns true if the actor is in the'actorNames' set
    return (actorNames.count(actor) == 1);
}

void Movie::insertActor(string actor){
    //Adds 'actor' to the set
    actorNames.insert(actor);
}


void Movie::removeActor(string actor){
    //Removes the specific 'actor' from the set
    actorNames.erase(actor);
}

string Movie::popActor(){
    //Removes actor from the set, once.
    string result;
    result = *actorNames.begin();
    actorNames.erase(result);
    return result;
}


