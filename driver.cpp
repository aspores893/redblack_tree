// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "RedBlackTree.h"
#include <vector>
#include <iostream>
#include <fstream>

/*
* Opens file specified by fileName  
* Pre-Conditions: Must have name of file to open
* Post-Condition: Opens specified file
*/
std::vector<int> openFile();

int main()
{
    std::vector<int> intVector = openFile(); //holds our data from file...
    
    RedBlackTree * newRedBlackTree = new RedBlackTree();
    for(int i = 0; i<intVector.size(); i++)
    {
        newRedBlackTree->insert(intVector.at(i));
    }

	std::cout << "Red Nodes: ";
    newRedBlackTree->printRedNodes(newRedBlackTree->getRoot());
    std::cout << std::endl;
	std::cout << "Black Nodes: ";
    newRedBlackTree->printBlackNodes(newRedBlackTree->getRoot());
    std::cout << std::endl;
	std::cout << "Root: " << newRedBlackTree->getRoot()->getNodeData();
    std::cout << std::endl;

    //delete all nodes from tree
    newRedBlackTree->deleteTree(newRedBlackTree->getRoot());
    //delete empty tree
    delete newRedBlackTree;

    return 0;
}

std::vector<int> openFile()
{
    std::string str_fileName;
    std::ifstream inStream("");
    std::string line; //holds line that was read in
    std::vector<int> vector_data;

    std::cout << "Please enter the name of the file to sort: ";

    std::cin >> str_fileName;

    std::cout << "\n";

	inStream.open(str_fileName.c_str());

	if (inStream.is_open()) //if the file is open...
	{
        while (std::getline(inStream,line,' '))
		{
            vector_data.push_back(stoi(line)); //pushes line's value to the back of the list
        }

		inStream.close();
    }
    else //if system can't open file...
    {
        std::cout << "Unable to open " << str_fileName << ". \nPlease ensure that you have typed the filename correctly, the file is not empty, or the file exists, and try again.\n" << std::endl;
    }
    return vector_data;
}