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
	
	void build()
	{
		
		while (!vCode.empty())
		{
			node * test = root;
			string tempCode = vCode.front();
			string tempLetter = vLetter.front();

			cout << tempCode << endl;
			cout << tempLetter << endl;

			for (int i = 0; i < tempCode.size(); i++)
			{
				if (tempCode[i] == '.')
				{
					if (test->left == NULL)
					{
						node * temp = new node;
						temp->code = tempCode;
						temp->letter = tempLetter;
						temp->right = NULL;
						temp->left = NULL;
						test->left = temp;
						
					}
					else
					{
						test = test->left;
					}
				}
				else if (tempCode[i] == '-')
				{
					if (test->right == NULL)
					{
						node * temp = new node;
						temp->code = tempCode;
						temp->letter = tempLetter;
						temp->right = NULL;
						temp->left = NULL;
						test->right = temp;
						
					}
					else
					{
						test = test->right;
					}
				}
			}
			vCode.pop();
			vLetter.pop();
		
		}

		
		
	}

	void searchInorder(node * node, string &result, char input)
	{
		if (node == NULL)
			return;

		searchInorder(node->left, result, input);

		if (node->letter[0] == input)
			result.append(node->code + " ");

		searchInorder(node->right, result, input);
	}

	void encode(string uInput)
	{
		string result;
		
		for (int i = 0; i < uInput.size(); i++)
		{
			if (uInput[i] == ' ')
				++i;
			searchInorder(root, result, uInput[i]);
		}
		
		cout << result;

	}





};

#endif
