#ifndef BACON
#define BACON

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


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
    bool isKnown;
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
    ifstream *inputstream;
    
    Parser(string inputFile);
    void RestartInput(string inputFile);
    class Movie* getNextMovie();
};

class MovieProcessor {
private:
    int pos; int it;
    bool isDone;
    vector<class Movie> unknownMovies;
    bool atEnd;
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
