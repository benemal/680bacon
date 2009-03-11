/*
 * Definition of BaconTree functions
 * Author: Grant Johnson
 * Date Created: 3-3-2009
 *
 */
#include "p3.h"
#include <iostream>

/* Adds a node to the tree.
 * 
 * Parameters:
 * 	t - pointer to a TreeNode to be inserted into the tree
 * 	parent - pointer to a TreeNode already in the tree that t will be inserted under.
 *
 * Requirements:
 * 	the actor represented by t must not exist in the tree.
 * 	the actor represented by parent must exist in the tree.
 *
 * Result:
 * 	t will be a child of parent.
 *  	t->parent will equal parent.
 *  	t->baconNumber will equal parent->baconNumber + 1
 *  	t->movieName is the name of the movie that the actors represented by t and parent were in together. This is already set by the client.
 *
 */
void BaconTree::AddTreeNode(class TreeNode *t, class TreeNode *parent) {
	// node to be inserted cannot exist in tree
	if(this->IsActorInTree(t->actorName)) {
		return;
	}

	// parent node must exist in tree
	if(!IsActorInTree(parent->actorName)) {
		return;
	}

	// Update t's parent, baconNumber
	t->parent = parent;
	t->baconNumber = parent->baconNumber + 1;

	// Handle internal objects
	actor_hash.insert(pair<string, class TreeNode*>(t->actorName, t)); 

	if(levelList.size() <= t->baconNumber) {
		levelList.resize(t->baconNumber + 1);
	}
	(levelList.at(t->baconNumber)).push_back(t);
}

/*	Checks for the existence of an actor in the tree.
 *
 *	Parameters: 
 *		actorName - a string representing the name of the actor to be searched for.
 *
 *	Return:
 *		true if the tree contains a node representing the actor named by actorName 
 *		false otherwise
 *
 */
bool BaconTree::IsActorInTree(string actorName) {
	return (this->actor_hash.count(actorName) == 1);
}

/*	Constructor
 *
 *	Result:
 *		Creates a new tree containing Kevin Bacon at the root.
 *
 */
BaconTree::BaconTree() {
	root = new TreeNode("Bacon, Kevin", "");
	root->baconNumber = 0;
	actor_hash.insert(pair<string, class TreeNode*>(root->actorName, root));
	levelList.resize(1);
	levelList.at(0).push_back(root);
}

/*	gets the TreeNode representing an actor
 *
 *	Parameters:
 *		actorName - the name of the actor to get the TreeNode for
 *
 *	Returns:
 *		pointer to a TreeNode representing the actor named by actorName
 */
class TreeNode* BaconTree::getTreeNode(string actorName) {
	if(IsActorInTree(actorName)) {
		return (actor_hash.find(actorName))->second;
	}
	else {
		return NULL;
	}
}

/*	Adds an actor to the tree.
 *
 *	Parameters:
 *		actorName - a string representing the actor to be inserted
 *		movieName - the movie actorName was in with parent
 *		parent - a TreeNode pointer already in the tree representing the actor to be connected to by actorName
 *
 *	Result:
 *		a new TreeNode is created and inserted into the tree. 
 *		(Note that if actorName is already in the tree or parent is NOT in the tree, then the tree will be unchanged.)
 *
 */
void BaconTree::AddActor(string actorName, string movieName, class TreeNode *parent) {
	TreeNode *t = new TreeNode(actorName, movieName);
	AddTreeNode(t, parent);
}


