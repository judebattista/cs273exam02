#include "PrefixTree.h"

#include <iostream>

bool TestPrefixTreeNode();

int main() {
	TestPrefixTreeNode();
}

bool TestPrefixTreeNode() {
	//Add a child
	PrefixTreeNode* root = new PrefixTreeNode('t');
	root->AddChild('h');
	std::cerr << "Root: " << root->Letter() << " Child h: " << root->GetChild('h')->Letter();
	return true;
}