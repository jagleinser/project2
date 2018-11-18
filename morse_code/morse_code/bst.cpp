#include "bst.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bst::bst()
{	
	string line;
	ifstream myFile("morse_file.txt");
	root = new node;
	root->left = NULL;
	root->right = NULL;

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
		
	}
	else
		cout << "ERROR: COULD NOT FIND FILE";

	build();

}
void bst::build()
{
	{

		while (!vCode.empty())
		{
			node * test = root;
			string tempCode = vCode.front();
			string tempLetter = vLetter.front();

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
void bst::decode(string uInput)
{
	uInput.append(" ");
	queue<string> tokens;

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
void bst::searchInorder(node * node, string &result, char input)
{
	if (node == NULL)
		return;

	searchInorder(node->left, result, input);

	if (node->letter[0] == input)
		result.append(node->code + " ");

	searchInorder(node->right, result, input);
}
void bst::encode(string uInput)
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


