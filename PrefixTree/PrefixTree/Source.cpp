#include "PrefixTree.h"

#include <ctime>
#include <iostream>


bool TestPrefixTreeNode();
bool TestPrefixTree();
void LoadPrefixTreeFromFile(std::string filename);
void TimeTrials(int iterations);

int main() {
	//TestPrefixTreeNode();
	//TestPrefixTree();
	//LoadPrefixTreeFromFile("..\\words.txt");
	TimeTrials(1);
}

void LoadPrefixTreeFromFile(std::string filename) {
	PrefixTree* tree = new PrefixTree("..\\words.txt", true);
	std::vector<std::string> foundWordsBrill = tree->FindWords("brill");
	std::cerr << "Words starting with 'brill': ";
	for (auto const& ndx : foundWordsBrill)
	{
		std::cerr << ndx << std::endl;
	}
	std::cerr << std::endl;
}

void TimeTrials(int iterations) {
	time_t begin, end;
	double totalElapsedTime = 0;
	std::cerr << "Loading words.txt " << iterations << " times WITHOUT constraints...\n";
	PrefixTree* tree;
	time(&begin);
	std::cerr << "Time started: " << begin << std::endl;
	for (int ndx = 0; ndx < iterations; ndx++) {
		tree = new PrefixTree("..\\words.txt", false);
	}
	time(&end);
	std::cerr << "Time ended: " << end << std::endl;
	totalElapsedTime = difftime(end, begin);
	std::cerr << "Total Elapsed Time: " << totalElapsedTime << ". Average Elapsed Time: " << totalElapsedTime / iterations << std::endl;
	std::cerr << "Loading words.txt " << iterations << " times WITH constraints...\n";
	totalElapsedTime = 0;
	time(&begin);
	std::cerr << "Time started: " << begin << std::endl;
	for (int ndx = 0; ndx < iterations; ndx++) {
		tree = new PrefixTree("..\\words.txt", false);
	}
	time(&end);
	std::cerr << "Time ended: " << end << std::endl;
	totalElapsedTime = difftime(end, begin);
	std::cerr << "Total Elapsed Time: " << totalElapsedTime << ". Average Elapsed Time: " << totalElapsedTime / iterations << std::endl;

}

bool NodeCanAddChild() {
	//Add a child
	PrefixTreeNode* root = new PrefixTreeNode('t');
	root->AddChild('h');
	char rootLetter = root->Letter();
	PrefixTreeNode* child = root->GetChild('h');
	char childLetter = child->Letter();
	std::cerr << "Root: " << root->Letter() 
		<< "\n     Child h: " << root->GetChild('h')->Letter() << '\n';
	return true;
}

bool NodeCanAddWord() {
	PrefixTreeNode* root = new PrefixTreeNode();
	root->AddWord("Hello", 0);
	std::cerr << root->GetChild('h')->Letter() << 
		root->GetChild('h')->GetChild('e')->Letter() <<
		root->GetChild('h')->GetChild('e')->GetChild('l')->Letter() <<
		root->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->Letter() <<
		root->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Letter();
	std::cerr << std::endl;
	std::cerr << "o marks the end of the word: " <<
		root->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Word() << std::endl;
	return true;
}

bool TestPrefixTreeNode() {
	NodeCanAddChild();
	NodeCanAddWord();
	return true;
}

bool CanCreateTree() {
	PrefixTree* tree = new PrefixTree();
	return true;
}

bool CanAddWordToTree() {
	PrefixTree* tree = new PrefixTree();
	tree->AddWord("Hello");
	std::cerr << tree->Root()->GetChild('h')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Letter();
	std::cerr << std::endl;
	std::cerr << "o marks the end of the word: " <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Word() << std::endl;
	return true;
}

bool CanAddTwoWordsToTree() {
	PrefixTree* tree = new PrefixTree();
	tree->AddWord("Hello");
	tree->AddWord("Hyper");
	std::cerr << tree->Root()->GetChild('h')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Letter();
	std::cerr << std::endl;
	std::cerr << "o marks the end of the word: " <<
		tree->Root()->GetChild('h')->GetChild('e')->GetChild('l')->GetChild('l')->GetChild('o')->Word() << std::endl;
	std::cerr << tree->Root()->GetChild('h')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('y')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('y')->GetChild('p')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('y')->GetChild('p')->GetChild('e')->Letter() <<
		tree->Root()->GetChild('h')->GetChild('y')->GetChild('p')->GetChild('e')->GetChild('r')->Letter();
	std::cerr << std::endl;
	std::cerr << "r marks the end of the word: " <<
		tree->Root()->GetChild('h')->GetChild('y')->GetChild('p')->GetChild('e')->GetChild('r')->Word() << std::endl;
	return true;
}

bool CanCheckForAString() {
	PrefixTree* tree = new PrefixTree();
	tree->AddWord("Jabberwocky");
	bool treeContainsJabber = tree->ContainsPrefix("Jabber") != NULL;
	bool treeContainsBrillig = tree->ContainsPrefix("Brillig") != NULL;
	std::cerr << "Tree contains the prefix 'Jabber': " << treeContainsJabber << std::endl;
	std::cerr << "Tree contains the prefix 'Brillig': " << treeContainsBrillig << std::endl;
	return true;
}

bool CanFindAllWordsBeginningWithPrefix() {
	PrefixTree* tree = new PrefixTree();
	tree->AddWord("Twas");
	tree->AddWord("Brillig");
	tree->AddWord("Brilliant");
	tree->AddWord("Slithy");
	tree->AddWord("Slither");
	tree->AddWord("Toves");
	std::vector<std::string> foundWordsBrill = tree->FindWords("brill");
	std::cerr << "Words starting with 'brill': ";
	for (auto const& ndx : foundWordsBrill)
	{
		std::cerr << ndx;
	}
	std::cerr << std::endl;
	std::vector<std::string> foundWordsSlith = tree->FindWords("slith");
	std::cerr << "Words starting with 'slith': ";
	for (auto const& ndx : foundWordsSlith)
	{
		std::cerr << ndx;
	}
	std::cerr << std::endl;
	return true;
}

bool TestPrefixTree() {
	CanCreateTree();
	CanAddWordToTree();
	CanAddTwoWordsToTree();
	CanCheckForAString();
	CanFindAllWordsBeginningWithPrefix();
	return true;
}