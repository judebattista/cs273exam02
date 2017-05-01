#pragma once

#include <map>
#include <string>
#include <vector>

class PrefixTreeNode {
	char letter;
	bool word;
	std::map<char, PrefixTreeNode*> children;

public:
	//Constructors
	PrefixTreeNode();
	PrefixTreeNode(char letter, bool endsWord = false);

	//Getters and setters
	char Letter() const;
	void Letter(char newLetter);
	bool Word() const;
	void Word(bool isAWord);
	PrefixTreeNode* GetChild(char childLetter);

	//Add a child to the node
	void AddChild(char childLetter, bool endsWord = false);

	//Remove a child from the node
	void RemoveChild(char childLetter);

	void AddWord(std::string word, int depth);

	//Find the substring of the word starting at the offset depth
	//amongst this node's children
	PrefixTreeNode* FindWord(std::string word, int depth);

	void FindAllPostfixes(std::vector <std::string> &foundWords, std::string postfixSoFar);
};
