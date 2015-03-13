# Introduction #

The following classes are used by bacon
  * BaconTree
  * TreeNode
  * Movie
  * Parser
  * MovieProcessor


# Details #
## BaconTree ##
BaconTree is a tree rooted at Kevin Bacon. Every leaf of the root has a bacon# of 1, and so on. All the leaves at level n of the tree have a bacon# of n.

Also included is a hash of actor names to pointers to TreeNodes in the BaconTree. This allows us to quickly locate an actor in the tree to output his relationship to Kevin Bacon.

Last is a vector of vectors of TreeNode pointers called levelList. All of the TreeNodes in levelList[n](n.md) have a bacon# of n.

## TreeNode ##
TreeNode represents an actor in the BaconTree.
TreeNode has the following members.
  * class TreeNode **parent` - pointer to that actor's parent, who is 1 degree closer to Kevin Bacon than the actor.
  * string actorName` - the name of the actor
  * string movieName` - the name of the movie this actor was in with the parent actor. In other words:
> `cout << this->actorName << " was in " << this->movieName << " with " << this->parent->actorName;`
  * int baconNumber` - the bacon# of this actor. Kept for quick reference.**

## Movie ##
The Movie class is a wrapper for a list of actor names, and the name of the movie they are in. Movie objects are produces by Parser and consumed by MovieProcessor.

## Parser ##
The Parser reads the input file and creates Movie objects.

> `class Movie getNextMovie()` - reads a line of input and returns a movie object representing the movie in that line.

## MovieProcessor ##
The MovieProcessor takes Movie objects and integrates them into a BaconTree. Since a movie might not have actors that can be connected to Kevin Bacon in the tree, it also maintains a list of movies that haven't been put in the tree yet.
### Members ###

  * BaconTree bt` - the BaconTree!
  * vector <class Movie> unknownMovies` - a list of movies not yet integrated into the BaconTree
  * Parser p` - the parser used by the MovieProcessor