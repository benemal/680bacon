#ifndef BACON
#define BACON

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct eqstr {
	bool operator()(const char* s1, const char* s2) {
		return strcmp(s1, s2) == 0;
	}
};

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

// List of Movies Objects (each containing a list of actors)

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

class Movie {
public:
    string movieName;
	set<string> actorNames;

    Movie(string movieName);
       
    bool actorIn(string actor);

    void insertActor(string actor);

    void removeActor(string actor);

    string popActor();

    int length();
};

class Parser {
	public:
    // parse input (movie Names, actors)
    ifstream *inputstream;

    Parser(string inputFile); //
    
    class Movie* getNextMovie(); /*{
		string movieName;
		// Get movie name
		class Movie result(movieName);
	// reads input file, creates Movie Object and returns that
	// Object (may return pointer - to lookup)
	//
	// To use this function:
	// 	class Movie m(getNextMovie());

		return result;
    }*/
};

class MovieProcessor {
private:
    vector<class Movie> unknownMovies;
    class Parser *p;
	BaconTree bacontree;
    
    void ProcessMovie(class Movie *m);

public:
    void ProcessInput(); 

    MovieProcessor(string inputFile);
    void PrintBaconChain(string actorName);
};

// List of functions to be implemented
void OutputChain(string actorName);
#endif
