#include "bst.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bst::bst()
{
	
	string line;
	string letter;
	string code;
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


