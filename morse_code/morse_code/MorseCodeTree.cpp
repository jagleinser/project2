#include "MorseCodeTree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Constructor for morse code tree
MorseCodeTree::MorseCodeTree()
{	
	//Load contents of file containing the morse code table
	string line;
	ifstream myFile("morse_file.txt");

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{	
			if (line.size() > 1) {
				vLetter.push(line.substr(0, 1));
				vCode.push(line.substr(2, line.size() - 1));
			}

		}
		myFile.close();
		//With the file loaded into vLetter & vCode, build the tree
		build();
	}
	else //If there is no file, we can't make the tree! This is a fatal exception!!!
		throw std::runtime_error("Could not open file");

}

//Builds the binary morse code tree from stored vector strings
void MorseCodeTree::build()
{
	//Initialize the the root node
	root = new node;
	root->left = NULL;
	root->right = NULL;
	{
		//For each entry in morse code
		while (!vCode.empty())
		{
			//Start from the root
			node * test = root;
			string tempCode = vCode.front();
			string tempLetter = vLetter.front();

			//Insert it into the tree
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
}

//Decodes a given morse string
void MorseCodeTree::decode(string uInput)
{
	uInput.append(" ");
	queue<string> tokens;

	//tokenize
	int counter = 0;
	for (int i = 0; i < uInput.size(); i++)
	{
		if (uInput[i] == ' ')
		{
			tokens.push(uInput.substr(counter, i - counter));
			counter = i + 1;
			++i;
		}
	}

	//for each token, find it in the tree
	while (!tokens.empty())
	{
		node * test = root;


		string find = tokens.front();
		for (int i = 0; i < find.size(); i++)
		{
			if (find[i] == '-')
				test = test->right;
			else
				test = test->left;
		}
		cout << test->letter;
		tokens.pop();
	}
}

//Searches the tree recursively in order, adding it to the result string
void MorseCodeTree::searchInorder(node * node, string &result, char input)
{
	//Base case - null
	if (node == NULL)
		return;

	//Search the left
	searchInorder(node->left, result, input);

	if (node->letter[0] == input)
		result.append(node->code + " ");

	searchInorder(node->right, result, input);
}

//Encodes a given string in the morse code and prints it
void MorseCodeTree::encode(string uInput)
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


