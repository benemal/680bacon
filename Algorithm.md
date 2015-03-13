# Introduction #

(there may be something missing...Grant)


# Details #

## MovieProcessor ##
  1. For each movie
    1. Find the actor with the lowest bacon#.
      1. if such an actor exists
        * insert that actor into the tree. All other actors become leaves of that actor.
      1. otherwise...
        * put that movie into the unknown list
  1. After all of the input is done.
    1. For each list in the BaconTree's levelList (from lowest to highest)
      1. for each actor in the list
        1. search the unknown movies for that actor.
          1. if a movie is found
            1. All other actors in the movie become leaves of that actor.
            1. Remove that movie from the unknown list.

## BaconTree ##
inserting an actor A with parent P
  1. set A's parent pointer to P
  1. set A's bacon# to P's bacon# + 1
  1. add (A->actorName, &A) to map.
  1. add &A to levelList[A->baconNumber]