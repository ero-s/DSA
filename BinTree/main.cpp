#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree* tree = new BinaryTree();
    
    // Adding nodes
    node* root = tree->addRoot(10);
    node* leftChild = tree->addLeft(root, 5);
    node* rightChild = tree->addRight(root, 15);
    
    // Adding more nodes
    tree->addLeft(leftChild, 3);
    tree->addRight(leftChild, 7);
    tree->addLeft(rightChild, 12);
    tree->addRight(rightChild, 18);
    
    // Printing the tree
    cout << "In-order traversal: ";
    tree->print();
    
    cout << "Pre-order traversal: ";
    tree->	printPreOrder(tree->getRoot());
    cout << endl;

    // Checking sibling
    node* siblingNode = tree->sibling(leftChild);
    if (siblingNode) {
        cout << "Sibling of " << leftChild->elem << " is " << siblingNode->elem << endl;
    } else {
        cout << "No sibling found." << endl;
    }

    // Removing a leaf node
    tree->remove(tree->left(leftChild));
    cout << "After removing 3, In-order traversal: ";
    tree->print();
    
    return 0;
}

