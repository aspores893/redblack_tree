// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#include "RedBlackTree.h"

enum nodeColor {black, red}; //0,1 

void RedBlackTree::insert(int data)
{
    TreeNode * newTreeNode = new TreeNode(data);
    TreeNode * root = insertNode(getRoot(), newTreeNode);
    setRoot(root);
    balanceColor(root, newTreeNode);
}
void RedBlackTree::printRedNodes(TreeNode * root)
{
    if (root == nullptr) 
    {
        return;
    }
        
    /* first recur on left child */
    printRedNodes(root->getLeftChild()); 

    if(root->isRed())
    {
        /* then print the data of node */
        std::cout << root->getNodeData() << " "; 
    }
    

    /* now recur on right child */
    printRedNodes(root->getRightChild()); 
}
void RedBlackTree::printBlackNodes(TreeNode * root)
{
    if (root == nullptr)
    {
        return; 
    } 
    

    if(!root->isRed())
    {
        /* then print the data of node */
        std::cout << root->getNodeData() << " "; 
    }

    /* then recur on left sutree */
    printBlackNodes(root->getLeftChild());  

    /* now recur on right subtree */
    printBlackNodes(root->getRightChild());
}
void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * rightNode = newNode->getRightChild();
    newNode->setRightChild(rightNode->getLeftChild());

    if(newNode->getRightChild() != nullptr)
    {
        newNode->getRightChild()->setParent(newNode);
    }

    rightNode->setParent(newNode->getParent());

    if(newNode->getParent() == nullptr)
    {
        root = rightNode;
        BinaryTree:setRoot(rightNode);
    }

    else if(newNode == newNode->getParent()->getLeftChild())
    {
        newNode->getParent()->setLeftChild(rightNode);
    }
    else
    {
        newNode->getParent()->setRightChild(rightNode);
    }
    rightNode->setLeftChild(newNode);
    newNode->setParent(rightNode);
    

}
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * leftNode = newNode->getLeftChild();
    newNode->setLeftChild(leftNode->getRightChild());

    if(newNode->getLeftChild() != nullptr)
    {
        newNode->getLeftChild()->setParent(newNode);
    }

    leftNode->setParent(newNode->getParent());

    if(newNode->getParent() == nullptr)
    {
        root = leftNode;
        BinaryTree:setRoot(leftNode);
    }

    else if(newNode == newNode->getParent()->getLeftChild())
    {
        newNode->getParent()->setLeftChild(leftNode);
    }
    else
    {
        newNode->getParent()->setRightChild(leftNode);
    }
    leftNode->setRightChild(newNode);
    newNode->setParent(leftNode);

}
void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * parentNode = nullptr;
    TreeNode * grandparentNode = nullptr;
    while ((newNode != root) && (newNode->isRed()!=black) && (newNode->getParent()->isRed()==red)) 
    {
        parentNode = newNode->getParent();
        grandparentNode = newNode->getParent()->getParent();

        //parent of newNode is left child of grandparent...
        if(parentNode == grandparentNode->getLeftChild())
        {
            TreeNode * auntNode = grandparentNode->getRightChild();

            //if aunt is red...
            if(auntNode != nullptr && auntNode->isRed()==red)
            {
                grandparentNode->setColor(red);
                parentNode->setColor(black);
                auntNode->setColor(black);
                newNode = grandparentNode;
            }

            else
            {
                //if newNode is the right child...
                if(newNode == parentNode->getRightChild())
                {
                    rotateLeft(root, parentNode);
                    newNode = parentNode;
                    parentNode = newNode->getParent();
                }
                else if(newNode == parentNode->getLeftChild())
                {
                    rotateRight(root, grandparentNode);
                    
                    //swap colors of parent and grandparent
                    swapColors(parentNode,grandparentNode);
                    newNode = parentNode;
                
                }
            }
                
        }
        //parent of newNode is the right child of grandparent...
        else
        {
            TreeNode * auntNode = grandparentNode->getLeftChild();

            //if aunt is red...
            if(auntNode != nullptr && auntNode->isRed()==red)
            {
                grandparentNode->setColor(red);
                parentNode->setColor(black);
                auntNode->setColor(black);
                newNode = grandparentNode;
            }
            else
            {
                //if newNode is the left child...
                if(newNode == parentNode->getLeftChild())
                {
                    rotateRight(root, parentNode);

                    newNode = parentNode;
                    parentNode = newNode->getParent();
                }
                else if(newNode == parentNode->getRightChild())
                {
                    rotateLeft(root, grandparentNode);

                    //swap colors of parent and grandparent
                    swapColors(parentNode,grandparentNode);
                    newNode = parentNode;
                }
                
            }
            
        }
        
    }
    root->setColor(false); //set root to black
}

void RedBlackTree::swapColors(TreeNode *& parentNode, TreeNode *& grandparentNode)
{
    bool parentColor = parentNode->isRed();
    bool grandparentColor = grandparentNode->isRed();

    parentNode->setColor(grandparentColor);
    grandparentNode->setColor(parentColor);
}