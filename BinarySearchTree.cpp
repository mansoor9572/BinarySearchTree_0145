#include <iostream>              // Include input/output stream library
using namespace std;             // Use the standard namespace

class Node                        // Define class Node representing a node in the tree
{
public:
    int info;                    // Integer data to store in the node
    Node * leftchild;             // Pointer to left child node
    Node *righchild;              // Pointer to right child node

    // Constructor for the node class
    Node(){
        leftchild = nullptr;      // Initialize left child to null
        righchild= nullptr;       // Initialize right child to null
    }
};

class BinaryTree                  // Define class BinaryTree for the binary search tree
{
public :
    Node *ROOT;                  // Pointer to the root node of the tree
    BinaryTree()
    {
        ROOT= nullptr;            // Initialize the tree as empty
    }

    void insert ()
    {
        int x;                    // Variable to hold value to insert
        cout<<"masulan nili :";   // Prompt user for input
        cin>>x;                  // Read input value

        // step 1: create a new node
        Node *newNode =new Node();
        // step2: store value in new node's data field
        newNode->info = x;
        