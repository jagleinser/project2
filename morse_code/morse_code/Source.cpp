#include <iostream>
#include "MorseCodeTree.h"
int main()
{
	MorseCodeTree bst; 
	bst.encode("rawr"); 
	bst.decode(".-. .- .-- .-.");

	system("pause");

}
