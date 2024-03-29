/*
 * Definition of BaconTree functions
 * Author: Grant Johnson
 * Date Created: 3-3-2009
 *
 */
#include "p3.h"
#include <iostream>

void BaconTree::AddTreeNode(class TreeNode *t, class TreeNode *parent) {
	TreeNode *temp;
	// node to be inserted cannot exist in tree
	if((temp = this->getTreeNode(t->actorName)) != NULL) { 
		 if(parent->baconNumber < temp->baconNumber-1) {
			temp->parent = parent;
			temp->baconNumber = temp->parent->baconNumber+1;
			temp->movieName = t->movieName;
			delete t;
			return;
		 }
	}

	t->parent = parent;
	t->baconNumber = parent->baconNumber + 1;
	actor_hash.insert(pair<string, class TreeNode*>(t->actorName, t)); 

	if(levelList.size() <= t->baconNumber) {
		levelList.resize(t->baconNumber + 1);
	}
	(levelList.at(t->baconNumber)).push_back(t);
}

bool BaconTree::IsActorInTree(string actorName) {
	return (this->actor_hash.count(actorName) == 1);
}

BaconTree::BaconTree() {
	root = new TreeNode("Bacon, Kevin", "");
	root->baconNumber = 0;
	actor_hash.insert(pair<string, class TreeNode*>(root->actorName, root));
	levelList.resize(1);
	levelList.at(0).push_back(root);
}

class TreeNode* BaconTree::getTreeNode(string actorName) {
	if(IsActorInTree(actorName)) {
		return (actor_hash.find(actorName))->second;
	} else {
		return NULL;
	}
}

void BaconTree::AddActor(string actorName, string movieName, class TreeNode *parent) {
	TreeNode *t = new TreeNode(actorName, movieName);
	AddTreeNode(t, parent);
}


