#include <iostream>
#include <string>
#include <Fstream>
#include <queue>
using namespace std;
#pragma once
#ifndef BST_H
#define BST_H

class bst {
private:
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
	bst();
	void build();
	void decode(string);
	void encode(string);
	void searchInorder(node * node, string &result, char input);

	




};

#endif
