// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "BinaryTree.h"
#ifndef RBT_H
#define RBT_H

// Header File for Red Black Tree. 
class RedBlackTree : public BinaryTree
{
public:
    //default constructor
    RedBlackTree(){}
    //default destructor
    ~RedBlackTree(){}
    /*
    * Pre-Conditions: Must have data to create TreeNode with, and the tree's root
    * Post-Condition: Creates TreeNode and calls BinaryTree:insertNode
    */
    virtual void insert(int data);
    /*
    * Pre-Conditions: Must have pointer to root of tree
    * Post-Condition: Prints all Red Nodes using an Inorder traversal method
    */
    void printRedNodes(TreeNode * root);
    /*
    * Pre-Conditions: Must have pointer to root of tree
    * Post-Condition: Prints all Black Nodes using a Preorder traversal method
    */
    void printBlackNodes(TreeNode * root);
    /*
    * Pre-Conditions: Must have pointers to parent and grandparent nodes
    * Post-Condition: Swaps colors of parent and grandparent nodes with eachother
    */
    void swapColors(TreeNode *& parentNode, TreeNode *& grandparentNode);

private:
    /* 
    * This allows us to perform a left rotational shift of our tree to ensure proper
    * balance is maintained. It will be called internally from our balanceColor
    * method 
    */
    void rotateLeft(TreeNode *& root, TreeNode *& newNode);
    /* 
    * This allows us to perform a right rotational shift of our tree to ensure proper
    * balance is maintained. It will be called internally from our balanceColor
    * method 
    */
    void rotateRight(TreeNode *& root, TreeNode *& newNode);
    /*
    * This method allows us to maintain proper balance within our tree and properly
    * adjusts the color of each node, if necessary, to adhere to the rules of a Red-Black
    * Tree.
    */
    void balanceColor(TreeNode *& root, TreeNode *& newNode);
};
#endif