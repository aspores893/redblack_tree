// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "Node.h"
#ifndef TREENODE_H
#define TREENODE_H

// Header File for TreeNode. 
class TreeNode : public Node
{
public:
    //constructor
    TreeNode(int data);
    //default constructor
    TreeNode();
    //default destructor
    ~TreeNode(){}
    /*
    * Post-Condition: Returns pointer to Parent of this node
    */
    TreeNode * getParent();
    /*
    * Post-Condition: Returns pointer to Left Child of this node 
    */
    TreeNode * getLeftChild();
    /*
    * Post-Condition: Returns pointer to Right Child of this node
    */
    TreeNode * getRightChild();
    /*
    * Post-Condition: Returns 0 (false) if the node's color is BLACK, or 1 (true) if the node's color is RED
    */
    bool isRed();
    /*
    * Pre-Conditions: Must have color (true = RED or false = BLACK) to change node's color to
    * Post-Condition: Changes node's color to provided boolean
    */
    void setColor(bool isRed);
    /*
    * Pre-Conditions: Must have pointer to node to change to parent
    * Post-Condition: Changes this node's Parent to provided node
    */
    void setParent(TreeNode * parent);
    /*
    * Pre-Conditions: Must have pointer to node to change to left child
    * Post-Condition: Changes this node's Left Child to provided node
    */
    void setLeftChild(TreeNode * leftChild);
    /*
    * Pre-Conditions: Must have pointer to node to change to Right Child
    * Post-Condition: Changes this node's Right Child to provided node
    */
    void setRightChild(TreeNode * rightChild);
private:
    TreeNode * parent_;
    TreeNode * leftChild_;
    TreeNode * rightChild_;
    bool isRed_;
};
#endif