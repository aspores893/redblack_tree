// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores
#include "TreeNode.h"
#include <iostream>
#ifndef BST_H
#define BST_H

// Header File for Binary Search Tree. 
class BinaryTree
{
public:
    //constructor
    BinaryTree();
    /*
    * Post-Condition: Returns root of BST
    */
    TreeNode * getRoot();
    /*
    * Pre-Conditions: Must have pointer to TreeNode to set as root
    * Post-Condition: Sets BST's root to pointer provided
    */
    void setRoot(TreeNode * root);
    /*
    * Pre-Conditions: Must have root of tree
    * Post-Condition: Deletes all TreeNodes from tree
    */
    void deleteTree(TreeNode * node);
    /*
    * Pre-Conditions: Must have data to insert
    * Post-Condition: Creates TreeNode and calls BinaryTree:insertNode
    */
    virtual void insert(int data);
    /*
    * Pre-Conditions: Must have pointer to TreeNode to insert
    * Post-Condition: Inserts provided TreeNode into tree, following BST rules
    */
    TreeNode * insertNode(TreeNode * root, TreeNode * node);
    
private:
    TreeNode * root_;

protected:
    //default destructor
    ~BinaryTree(){}
};
#endif