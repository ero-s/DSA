#include <iostream>
#include "node.h"
#include "list.h"
#include <stdexcept>
using namespace std;


class BinaryTree : public List{
    int size;
    node* root;

public:
    BinaryTree() : size(0), root(NULL) {}

    node* getRoot() { return root; }

    node* addRoot(int num) {
        if (!root) {
            root = new node();
            root->elem = num;
            size++;
            cout << num << " root added" << endl;
            return root;
        }
        throw runtime_error("Already has root");
    }

    node* addLeft(node* n, int num) {
        if (!n->left) {
            node* l = new node();
            l->elem = num;
            l->parent = n;
            n->left = l;
            cout << num << " Left added" << endl;
            return l;
        }
        throw runtime_error("Already has left node");
    }

    node* addRight(node* n, int num) {
        if (!n->right) {
            node* r = new node();
            r->elem = num;
            r->parent = n;
            n->right = r;
            cout << num << " Right added" << endl;
            return r;
        }
        cout << "Already has right" << endl;
        return NULL;
    }

    node* remove(node* n) {
        if (n == NULL) throw runtime_error("Node is null");
        if (n->left || n->right) throw runtime_error("Node has children");

        node* parent = n->parent;
        if (parent) {
            if (parent->left == n) parent->left = NULL;
            else if (parent->right == n) parent->right = NULL;
        } else {
            root = NULL; // Removing root node
        }
        delete n;
        size--;
        return parent;
    }

    node* sibling(node* n) {
        if (n && n->parent) {
            node* parent = n->parent;
            return (n == parent->left) ? parent->right : parent->left;
        }
        return NULL;
    }

    node* left(node* n) { return n->left; }

    node* right(node* n) { return n->right; }

    void print() {
        if (!root) {
            throw runtime_error("Tree is empty. No elements to print.");
        }
        cout << "Binary Tree elements (In-Order Traversal): ";
        printInOrder(root);
        cout << endl;
    }

    void printInOrder(node* n) {
        if (n) {
            printInOrder(n->left);
            cout << n->elem << " ";
            printInOrder(n->right);
        }
    }

    void printPreOrder(node* n) {
        if (n) {
            cout << n->elem << " ";
            printPreOrder(n->left);
            printPreOrder(n->right);
        }
    }
};
