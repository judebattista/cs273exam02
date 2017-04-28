#include "PrefixTree.h"

//Constructors
PrefixTree::PrefixTree(char rootLetter) {
	root = new PrefixTreeNode(rootLetter);
}

//Getters and setters

//Add a letter to the tree
void PrefixTree::Add(char letter) {
	root->AddChild(letter);
}

//Remove letter from tree
void PrefixTree::Remove(char letter) {
	root->RemoveChild(letter);
}

bool PrefixTree::IsAWord() {
	return root->Word();
}

std::vector<std::string> PrefixTree::FindWords(std::string prefix) {
	std::vector<std::string> words;
	//Recursion
	return words;
}