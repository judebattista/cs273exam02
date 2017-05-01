#include "PrefixTree.h"

#include <fstream>
#include <iostream>


//Constructors
PrefixTree::PrefixTree() {
	root = new PrefixTreeNode();
}

//Create a tree based on a list of words in a file
//ineligibleChars has a default of "&\'\\/0123456789"
PrefixTree::PrefixTree(std::string fileName, bool useConstraint, std::string ineligibleChars) {
	root = new PrefixTreeNode();
	//create an ifstream and open the file
	std::ifstream inputStream;
	inputStream.open(fileName);
	if (!inputStream.is_open())
	{
		//TODO: throw an exception here?
		return;
	}
	std::string word;
	//Read each word from the ifstream
	while (inputStream >> word) {
		if (useConstraint) {
			//If we don't find any ineligible chars...
			if (word.find_first_of(ineligibleChars) == std::string::npos)
			{
				//...add the word to the tree
				//TODO: Figure out why this errors out.
				this->AddWord(word);
			}
		}
		else {
			this->AddWord(word);
		}
	}
	inputStream.close();
}

//Getters and setters
PrefixTreeNode* PrefixTree::Root() const {
	return root;
}

//Add a letter to the tree
void PrefixTree::AddLetter(char letter) {
	root->AddChild(letter);
}

//Remove letter from tree
void PrefixTree::RemoveLetter(char letter) {
	root->RemoveChild(letter);
}

//Add a word to the tree
void PrefixTree::AddWord(std::string word) {
	root->AddWord(word, 0);
}

PrefixTreeNode* PrefixTree::ContainsPrefix(std::string prefix) {
	//Walk tree using prefix, starting at root
	PrefixTreeNode* endOfPrefix = root->FindWord(prefix, 0);
	return endOfPrefix;
}

std::vector<std::string> PrefixTree::FindWords(std::string prefix) {
	//clear any data in foundWords
	foundWords.clear();
	//Walk tree to find prefix
	PrefixTreeNode* endOfPrefix = ContainsPrefix(prefix);
	//This will update foundWords
	//TODO refactor this so it doesn't rely on side effects?
	//Tough to do with recursion
	endOfPrefix->FindAllPostfixes(this->foundWords, prefix);
	return foundWords;
}