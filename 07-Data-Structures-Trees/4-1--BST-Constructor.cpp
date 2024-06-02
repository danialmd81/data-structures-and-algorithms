#include <iostream>

using namespace std;

// CREATE NODE CLASS HERE //
class Node
{
public:
    Node *left, *right;
    int value;
    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree()
    {
        root = nullptr;
    }
    // CREATE MEMBER VARIABLE HERE //

    // CREATE BST CONSTRUCTOR HERE //

    // ---------------------------------------------------
    //  Below is a helper function used by the destructor
    //  Deletes all nodes in BST
    //  Similar to DFS PostOrder in Tree Traversal section
    // ---------------------------------------------------
    void destroy(Node *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }
};

int main()
{

    BinarySearchTree *myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */
}
