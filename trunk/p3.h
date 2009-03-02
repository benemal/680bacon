#include <string>
#include <vector>
#include <map>

using namespace std;

struct eqstr {
	bool operator()(const char* s1, const char* s2) {
		return strcmp(s1, s2) == 0;
	}
};

class TreeNode {
public:
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

// List of Movies Objects (each containing a list of actors)

class BaconTree {
public:
    TreeNode root; //bacon# 0
	map<string, class TreeNode*> actor_hash;
    //HashTable<string> actors  // hashtable of actors in the Bacon
    //tree

    vector<vector<class TreeNode *> > levelList;

    void AddTreeNode(class TreeNode * t, class TreeNode * parent) {
	//adds the given node to the tree
    }

    bool IsActorInTree(string name) {
	//
    }
};   

class Movie {
private:
	vector<string> actorNames;
public:
    string name;

    Movie(string name) {
	this->name = name;
	//Handle list instantiation
    }
       
    bool actorIn(string actor) {
	// Returns true if actor is in movie
    }

    void insertActor(string actor) {
	// insert actor into list
    }

    void removeActor(string actor) {
	// removes actor from list
    }

    string popActor() {
		string actorName;
		// pop all actors from the list one at a time
		return actorName;
    }

    int length() {
	// return size of list
    }
};

class Parser {
	public:
    // parse input (movie Names, actors)

    Parser(string inputFile) {
	//
    }
    
    class Movie getNextMovie() {
		string movieName;
		// Get movie name
		class Movie result(movieName);
	// reads input file, creates Movie Object and returns that
	// Object (may return pointer - to lookup)
	//
	// To use this function:
	// 	class Movie m(getNextMovie());

		return result;
    }
};

class MovieProcessor {
private:
    vector<class Movie> unknownMovies;
    class Parser *p;
    
    void ProcessMovie(class Movie m) {
	//
    }

public:
    class BaconTree ProcessInput() {
	//
    }

    MovieProcessor(string inputFile) {
		p = new Parser(inputFile);
    }
};

// List of functions to be implemented
void OutputChain(string actorName);
void PrintBaconChain(string actorName);
