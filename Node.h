// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// aspores

#ifndef NODE_H
#define NODE_H

// Header File for Node class. 
class Node
{
public:
    /*
    * Constructor for Node 
    * Pre-Conditions: Must have element to insert
    * Post-Condition: Creates Node with specified element
    */
    Node(int element);
    //default destructor
    ~Node() {}
    /*
    * Post-Condition: Returns data in Node
    */
    int getNodeData();

private:
    int data_;

protected:
    //default constructor
    Node() {}
};
#endif