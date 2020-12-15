// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "BinaryTree.h"

BinaryTree::BinaryTree() : root_(nullptr)
{
    
}
void BinaryTree::deleteTree(TreeNode * node)
{
    if(node==nullptr)
    {
        return;
    }
    
      /* first recur on left child */
        deleteTree(node->getLeftChild());
    
        /* now recur on right child */
        deleteTree(node->getRightChild());
        
    delete node;
     
}
TreeNode * BinaryTree::getRoot()
{
    return root_;
}
void BinaryTree::setRoot(TreeNode * root)
{
    root_ = root;
}
void BinaryTree::insert(int data)
{
    TreeNode * newTreeNode = new TreeNode(data);
    root_ = insertNode(root_, newTreeNode);
}
TreeNode * BinaryTree::insertNode(TreeNode * root, TreeNode * node)
{
    if(root == nullptr)
    {
        return node;
    }
    if(node->getNodeData() < root->getNodeData())
    {
        root->setLeftChild(insertNode(root->getLeftChild(), node));
        root->getLeftChild()->setParent(root);
    }
    else if(node->getNodeData() > root->getNodeData())
    {
        root->setRightChild(insertNode(root->getRightChild(), node));
        root->getRightChild()->setParent(root);
    }
    return root;
}


