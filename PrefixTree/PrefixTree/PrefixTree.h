#pragma once

#include "PrefixTreeNode.h"

#include <string>
#include <vector>

class PrefixTree {
	PrefixTreeNode* root;
	std::vector<std::string> foundWords;

public:
	//Constructors
	PrefixTree();
	//Create a tree based on a list of words in a file
	PrefixTree(std::string fileName, bool useConstraint, std::string ineligibleChars = "&\'\\/0123456789");

	//Getters and setters
	PrefixTreeNode* Root() const;

	//Add a letter to the tree
	void AddLetter(char letter);

	//Remove letter from tree
	void RemoveLetter(char letter);

	//Add a word to the tree
	void AddWord(std::string word);

	PrefixTreeNode* ContainsPrefix(std::string prefix);

	std::vector<std::string> PrefixTree::FindWords(std::string prefix);
};