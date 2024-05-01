#pragma once
#include <iostream>
#include <string>

using namespace std;
// define a struct for a node in the binary tree
struct Node {
    string data;
    Node* left;
    Node* right;
    int level;//for insert and copy 

    // constructor for a node, initializes data/level for the copy function and left/right pointers to null  
    Node(string data, int level){
        // Initialize the member variables "data" and "level" with the parameter values
        this->data = data;
        this->level = level;
        // Initialize the member variables "left" and "right" to null pointers
        this->left = nullptr;
        this->right = nullptr;
    }
};

// define a class for the binary tree
class BinTree {
public:
    Node* theRoot;// root node of the tree(public for int main reasons)
    // constructor for the binary tree, initializes root to null
    BinTree() {
        theRoot = nullptr;
    }
    // destructor for the binary tree, recursively removes all nodes in the tree
    ~BinTree() { 
        removeAll(theRoot); 
    }

    /*This is a function that inserts a new node into a binary tree.if the child 
    reaches a dead end, the parent creates a new path and sets it as the child's
    new route. But if the child encounters a fork, the parent tells them which
    direction to take based on whether the data is less than or greater 
    than the current node's data.*/
    void insert(Node*& node, string data, int level) {
        if (node == nullptr) {
            node = new Node(data, level);// create a new node with the given data and level and set it as the node
        }
        else if (data < node->data) {
            insert(node->left, data, level + 1);// recursively insert the node to the left subtree
        }
        else {
            insert(node->right, data, level + 1);// recursively insert the node to the right subtree
        }
    }

    /*
    Traverse the tree and find the node to delete. If you reach a null node, 
    the node to delete isn’t in the tree and you can return false. Otherwise
    current is a pointer to the node to delete
    previous is the parent of the node to delete
    */
    void remove(Node*& node, string dataToDelete) {
        if (node == nullptr) {
            return; // if the node is null, then the data is not in the tree and we can just return
        }
        else if (dataToDelete < node->data) {
            remove(node->left, dataToDelete);// recursively remove the node from the left subtree
        }
        else if (dataToDelete > node->data) {
            remove(node->right, dataToDelete);// recursively remove the node from the right subtree
        }
        else {//if its equal to the data...
            if (node->left == nullptr && node->right == nullptr) {
                delete node;// if the node has no children, we can just delete it
                node = nullptr;// set the node to null to indicate it has been deleted
            }
            else if (node->left == nullptr) {
                Node* replacement = node; 
                // if the node has only a right child, replace it with the right child
                node = node->right;
                delete replacement;// delete the original node
            }
            else if (node->right == nullptr) {
                Node* replacement = node;
                node = node->left;// if the node has only a left child, replace it with the left child
                delete replacement; // delete the original node
            }
            else {
                Node* replacement = findMin(node->right);// find the minimum node in the right subtree
                node->data = replacement->data;// copy the minimum node's data to the current node(the minimum node will be the smallest node that is greater than the current node)
                remove(node->right, replacement->data);// remove the old minimum node from the right subtree
            }
        }
    }
    // finds the minimum node in the binary tree starting from the given node @returns the minimum node
    Node* findMin(Node* node) {
        while (node->left != nullptr) {//goes to the most left side of tree till its null
            node = node->left;
        }
        return node;
    }

    /* it visits the nodes in ascending order based on their values. It starts 
    from the left-most node and works its 
    way up to the right-most node, printing out
    each node's data and level along the way*/ 
    void inOrder(Node* node) {
        if (node != nullptr) {//when "node" hits a null node it will activate this base case
            inOrder(node->left);//first left traversal recusivly 
            cout << node->data << "(" << node->level << ")-> ";
            inOrder(node->right);//after left nodes hit null, then the right sub tree can be searched
        }
    }

    /*It traverses through the left and right branches first to make sure it doesn't forget anyone,
    and only then does it print out the node's data*/
    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << "(" << node->level << ")-> ";
        }
    }

    /* it visits the nodes in a top to bottom, starting from the root and moving to 
    the left and right subtrees. It prints out each node's data and level 
    before recursively traversing through its left and right children.*/
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << "(" << node->level << ")-> ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    /*This function creates a copy of the binary tree and returns it as a new binary tree 
    object. It creates a new empty binary tree, then recursively
    copies each node and its subtree from the original tree into the new treefrom the root.*/
    BinTree* copy() const {
        BinTree* newTree = new BinTree();
        copy(newTree->theRoot, theRoot);
        return newTree;
    }

    // removes all nodes in the binary tree starting from the given node
    void removeAll(Node* node) {
        if (node != nullptr) {
            removeAll(node->left);// recursively remove the left subtree
            removeAll(node->right);// recursively remove the right subtree
            delete node;
            node = nullptr;
        }
    }

private:
    /*
     It takes two inputs, one is the new empty tree and the other is the old 
     tree that we want to copy. If the old tree is empty, there's nothing to copy, so the
     function stops. Other than that it creates a new node in the new tree with the
     same data and level as the node in the old tree, and then it recursively 
     copies the left and right subtrees of the old tree. Its private because its 
     an internal funtion in the class and is not refrenced outside of this class.
     @param newTree- an empty tree to be built on 
     @param oldTree oldTree- the tree to be copied
    */
    void copy(Node*& newTree, Node* oldTree) const {
        if (oldTree == nullptr) {//if its empty then dont copy it(base case)
            return;
        }
        newTree = new Node(oldTree->data, oldTree->level);//theres two input paramenters in the constructor which enable this
        copy(newTree->left, oldTree->left);//kinda the same thing as the pre order recusion 
        copy(newTree->right, oldTree->right);
    }
};

