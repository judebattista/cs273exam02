#pragma once

#include <map>

class PrefixTreeNode {
	char letter;
	bool word;
	std::map<char, PrefixTreeNode*> children;

public:
	//Constructors
	PrefixTreeNode(char);

	//Getters and setters
	char Letter();
	void Letter(char newLetter);
	bool Word();
	void Word(bool isAWord);
	PrefixTreeNode* GetChild(char childLetter);

	//Add a child to the node
	void AddChild(char childLetter);

	//Remove a child from the node
	void RemoveChild(char childLetter);
};
