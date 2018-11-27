#include <iostream>
#include <string>
#include <Fstream>
#include <queue>
using namespace std;
#pragma once

class MorseCodeTree {
private:
	//Internal structure for nodes of a binary tree
	struct node {
		string letter;
		string code;
		node * left;
		node * right;
		

	};
	node * root;
	
	queue<string> vCode;
	queue<string> vLetter;
public:
	MorseCodeTree();
	void build();
	void decode(string);
	void encode(string);
	void searchInorder(node * node, string &result, char input);

	




};