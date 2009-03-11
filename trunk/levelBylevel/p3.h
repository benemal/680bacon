#ifndef BACON
#define BACON

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*	a single node in the bacon tree
 *
 * 	Members:
 * 		actorName - name of actor represented
 * 		baconNumber - the number of degrees separating this actor from Kevin Bacon
 * 		movieName - the movie the represented actor was in with its parent
 *
 * 	Methods:
 * 		TreeNode - constructor
 *
 */
class TreeNode {
public:
    friend class BaconTree;
    string actorName;
    int baconNumber; 
    string movieName;
    class TreeNode* parent;

    TreeNode(string actor, string movie) {
	this->actorName = actor;
	this->movieName = movie;
	this->parent = NULL;
    }
};

/*	tree connecting actors to Kevin Bacon
 *	Each level of the tree contains all of the actors a number of degrees from Kevin Bacon.
 *	The tree is rooted at Kevin Bacon, and lower levels are progressively further away.
 *
 *	Members:
 *		root - the root of the tree
 *		actor_hash - not really a hash, it maps actor names to their representative tree nodes
 *		levelList - a list of lists of TreeNode pointers. levelList[n] contains all of the TreeNodes at level n in the tree.
 *
 *	Methods:
 *		AddTreeNode - add a given TreeNode to the tree under given parent already in tree
		AddActor - create a TreeNode from given actor, movie and add it to the tree
 *		IsActorInTree - check if the tree contains an actor
 *		getTreeNode - get TreeNode in tree representing a given actor
 *
 */
class BaconTree {
public:
    TreeNode *root; //bacon# 0
    map<string, class TreeNode*> actor_hash;
    vector<vector<class TreeNode *> > levelList;

    void AddTreeNode(class TreeNode * t, class TreeNode * parent); 
    void AddActor(string actorName, string movieName, class TreeNode *parent);
    bool IsActorInTree(string actorName);
    class TreeNode* getTreeNode(string actorName);
    BaconTree(); 
};   

/* 	representation of a single movie and its cast
 *
 * 	Members:
 * 		movieName - name of movie
 * 		isKnown - has the movie been added to the tree?
 * 		actorNames - names of the actors in the movie
 *
 * 	Methods:
 * 		Movie - constructor. Creates a new movie with given name
 * 		actorIn - check if a given actor is in the movie
 * 		insertActor - add a given actor to the movie
 * 		removeActor - remove a given actor from the movie
 * 		popActor - remove an arbitrary actor from the movie and return his/her name
 *
 */
class Movie {
public:
    string movieName;
    bool isKnown;
    set<string> actorNames;
    
    Movie(string movieName);
    bool actorIn(string actor);
    void insertActor(string actor);
    void removeActor(string actor);
    string popActor();
};

/*	reads input file and creates class Movie objects
 *
 *	Members:
 *		inputstream - stream used to read the input file.
 *
 *	Methods:
 *		Parser - constructor. Creates a parser to read a given input file
 *		getNextMovie - read next movie from the input and create and return a class Movie object representing it.
 *
 */
class Parser {
public:
    ifstream *inputstream;
    
    Parser(string inputFile);
    class Movie* getNextMovie();
};

/*	translates input file to a bacon tree
 *
 *	Members:
 *		private: 
 *                      it - iterator which at anytime has the value of current levellist
 *			unknownMovies - vector to hold all 'Movie' objects
 *			p - parser to read input file
 *			bacontree - tree created from input file
 *			
 *	Methods:
 *		private:
 *			ProcessMovie - process each movie in the input
 *			file partially (finds movies with Kevin
 *			Bacon and adds the rest of movies to
 'unknownMovies' vector.
 *
 *		public:
 *			ProcessInput - processes all the movies in the
 'unknownmovies' vector.
 *			PrintBaconChain - output the relationship of a
 given actor to Kevin Bacon
 *			ProcessTreesNmovies - finds an actor with
minimum bacon number in each movie and
populates the 'bacontree'.
 *
 */
class MovieProcessor {
private:
    int it;
    vector<class Movie> unknownMovies;
    class Parser *p;
    BaconTree bacontree;
    void ProcessMovie(class Movie *m);
    
public:
    void ProcessInput();
    MovieProcessor(string inputFile);
    void PrintBaconChain(string actorName);
    void ProcessTreesNmovies(class Movie *m);
};

#endif
