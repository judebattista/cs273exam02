#include "PrefixTreeNode.h"

//Constructors
PrefixTreeNode::PrefixTreeNode() {
	word = false;
}

//endsWord defaults to false
PrefixTreeNode::PrefixTreeNode(char letter, bool endsWord) {
	this->letter = letter;
	word = endsWord;
}

//Getters and setters
char PrefixTreeNode::Letter() const {
	return this->letter;
}
void PrefixTreeNode::Letter(char newLetter) {
	this->letter = newLetter;
}
bool PrefixTreeNode::Word() const {
	return this->word;
}
void PrefixTreeNode::Word(bool isAWord) {
	this->word = isAWord;
}
PrefixTreeNode* PrefixTreeNode::GetChild(char childLetter) {
	return children[childLetter];
}

//endsWord defaults to false
void PrefixTreeNode::AddChild(char childLetter, bool endsWord) {
	//Check if letter is valid
	childLetter = tolower(childLetter);
	if (childLetter < 'a' || childLetter > 'z') {
		//TODO: add handlers for this wherever we call AddChild
		//throw std::out_of_range(childLetter + " is not between a and z");
	}
	//If letter is not in children, add letter to children
	if (children[childLetter] == NULL) {
		children[childLetter] = new PrefixTreeNode(childLetter, endsWord);
	}
}

//Remove a child from the node
void PrefixTreeNode::RemoveChild(char childLetter) {
	//TODO fix this
	//If letter exists in children remove it
	//Otherwise do nothing
}

//Add a word to a node
void PrefixTreeNode::AddWord(std::string word, int depth) {
	//Get the next letter to add from word
	char nextLetter = tolower(word[depth]);
	//If the letter isn't a child, add it
	this->AddChild(nextLetter);
	//If we're not at the end of the word, look for the next letter
	//in the children of the current node
	if (depth < word.length() - 1) {
		children[nextLetter]->AddWord(word, depth + 1);
	}
	else { //If we are at the end of the word, set the Word boolean
		children[nextLetter]->Word(true);
	}
}

//Find the substring of the word starting at the offset depth
//amongst this node's children
PrefixTreeNode* PrefixTreeNode::FindWord(std::string word, int depth) {
	//If we've found or passed the last letter in the word, return the current node
	//TODO: if we've somehow passed the last letter throw an error
	if (depth >= word.size()) {
		return this;
	}
	//Get the next letter to add from word
	char nextLetter = tolower(word[depth]);
	if (children[nextLetter] == NULL) { //If the letter isn't amongst the children, return null
		return NULL;
	}
	//Otherwise, if we're not at the end of the word, look for the next letter
	//in the children of the current node
	 else if (depth < word.length()) {
		return children[nextLetter]->FindWord(word, depth + 1);
	}
}

//Do a full tree walk starting at the current node. If we find a node marked as the end of a word, add it to foundWords
void PrefixTreeNode::FindAllPostfixes(std::vector<std::string> &foundWords, std::string postfixSoFar) {
	//If the current node ends a word, add it to the list of foundWords
	if (this->word) {
		foundWords.push_back(postfixSoFar);
	}
	//Check every child.
	//We need to exhaust one child before moving to the next
	for (auto const& ndx : children) {
		//add child's character to the postfixSoFar and search it's children
		ndx.second->FindAllPostfixes(foundWords, postfixSoFar+ndx.first);
	}
}
