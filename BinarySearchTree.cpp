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
        // step 3: make its left and right pointers null
        newNode-> leftchild= nullptr;
        newNode->righchild =nullptr;
        // step 4: declare pointers to help with search
        Node *parent = nullptr;
        Node *currentNode =nullptr;
        search(x,parent,currentNode);  // Search for insertion point

        // step 5: if parent is null, then the tree was empty
        if (parent == nullptr)
        {
            // 5a: make the new node the root
            ROOT = newNode;
            // 5b: return because insertion is done
            return;
        }
        // step 7: if value is greater than parent's value
        else if (x > parent->info)
        {
            // 7a: insert new node as the right child of parent
            parent->righchild =newNode;
            // 7b: return after insertion
            return;
        }
    }

    void search(int element ,Node *&parent, Node *&currentNode)
    {
        // this function searches for a node containing 'element'
        currentNode = ROOT;             // Start at the root node
        parent =nullptr;                // Initially, parent is null
        // Traverse until you find the node or hit null
        while ((currentNode != nullptr )&&(currentNode->info != element))
        {
            parent = currentNode;       // Save current node as parent
            if (element < currentNode->info)  // If value is smaller, go left
            {
                currentNode= currentNode->leftchild;
            }
            else                         // Otherwise go right
                currentNode =currentNode->righchild;
        }
    }

    void inorder(Node *ptr)
    {
        // Print the tree using inorder traversal (Left, Node, Right)
        if (isEmpty())                // Check if the tree is empty
        {
              cout<<"tree is empty"<<endl;
              return;
        }
        if (ptr == nullptr)           // Base case: node is null
            return;

        inorder(ptr->leftchild);       // Traverse left subtree
        cout<<ptr->info<<endl;         // Print node data
        inorder(ptr->righchild);       // Traverse right subtree
    }

    void preorder(Node *ptr)
    {
        // Print the tree using preorder traversal (Node, Left, Right)
        if (isEmpty())                // Check if tree is empty
        {
              cout<<"tree is empty"<<endl;
              return;
        }
        if (ptr == nullptr)           // Base case
            return;

        cout<<ptr->info<<endl;         // Print node data
        preorder(ptr->leftchild);      // Traverse left subtree
        preorder(ptr->righchild);      // Traverse right subtree
    }

    void postorder(Node *ptr)
    {
        // Print the tree using postorder traversal (Left, Right, Node)
        if (isEmpty())                // Check if the tree is empty
        {
              cout<<"tree is empty"<<endl;
              return;
        }
        if (ptr == nullptr)           // Base case
            return;

        postorder(ptr->leftchild);     // Traverse left subtree
        postorder(ptr->righchild);     // Traverse right subtree
        cout<<ptr->info<<endl;         // Print node data
    }

    bool isEmpty()
    {
        // Return true if the tree's ROOT is null
        return ROOT == nullptr;
    }

    
};
int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }

}

