// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "TreeNode.h"

TreeNode::TreeNode(int data) : Node(data), parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr), isRed_(true)
{

}
TreeNode * TreeNode::getParent()
{
    return parent_;
}
TreeNode * TreeNode::getLeftChild()
{
    return leftChild_;
}
TreeNode * TreeNode::getRightChild()
{
    return rightChild_;
}
void TreeNode::setParent(TreeNode * parent)
{
    parent_ = parent;
}
void TreeNode::setLeftChild(TreeNode * leftChild)
{
    leftChild_ = leftChild;
}
void TreeNode::setRightChild(TreeNode * rightChild)
{
    rightChild_ = rightChild;
}
bool TreeNode::isRed()
{
    return isRed_;
}
void TreeNode::setColor(bool isRed)
{
    isRed_ = isRed;
}