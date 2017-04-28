#pragma once

#include "PrefixTreeNode.h"

#include <string>
#include <vector>

class PrefixTree {
	PrefixTreeNode* root;

public:
	//Constructors
	PrefixTree(char rootLetter);

	//Getters and setters

	//Add a letter to the tree
	void Add(char letter);

	//Remove letter from tree
	void Remove(char letter);

	bool IsAWord();

	std::vector<std::string> FindWords(std::string prefix);
};