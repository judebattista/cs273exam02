#include "PrefixTreeNode.h"

#include <string>

PrefixTreeNode::PrefixTreeNode(char letter) {
	this->letter = letter;
	word = false;
}

char PrefixTreeNode::Letter() {
	return this->letter;
}
void PrefixTreeNode::Letter(char newLetter) {
	this->letter = newLetter;
}
bool PrefixTreeNode::Word() {
	return this->word;
}
void PrefixTreeNode::Word(bool isAWord) {
	this->word = isAWord;
}
PrefixTreeNode* PrefixTreeNode::GetChild(char childLetter) {
	return children[childLetter];
}
void PrefixTreeNode::AddChild(char childLetter) {
	//TODO FIX THIS
	//Check if letter is valid
	childLetter = tolower(childLetter);
	if (childLetter < 'a' || childLetter > 'z') {
		throw std::out_of_range(childLetter + " is not between a and z");
	}
	//If letter exists in children, do nothing?
	//Otherwise, add letter to children
	if (children[childLetter] != NULL) {
		children[childLetter] = new PrefixTreeNode(childLetter);
	}
}

//Remove a child from the node
void PrefixTreeNode::RemoveChild(char childLetter) {
	//TODO fix this
	//If letter exists in children remove it
	//Otherwise do nothing
}

