/*
Author: kaevin Barta
Version: 1.0
file: BinarySearchTrees.snl 

This program is to practice using recursion and help us better understand binary search
trees. The program comes equipped with pre/post/in-Order traversals of the lists
with all functions clearly labeled and commented on.
*/

#include <iostream>
#include "SearchTree.h"

int main() {

	cout << "CS 260 Assignment 3 - Binary Search Trees\n";
	cout << "Kaevin Barta :)\n";

	BinTree tree;

	tree.insert(tree.theRoot, "Jynx", 0);
	tree.insert(tree.theRoot, "Charmander", 0);
	tree.insert(tree.theRoot, "Snorlax", 0);
	tree.insert(tree.theRoot, "Clefairy", 0);
	tree.insert(tree.theRoot, "Diglett", 0);
	tree.insert(tree.theRoot, "Kakuna", 0);
	tree.insert(tree.theRoot, "Meowth", 0);
	tree.insert(tree.theRoot, "Nidorino", 0);
	tree.insert(tree.theRoot, "Pikachu", 0);
	tree.insert(tree.theRoot, "Blastoise", 0);
	tree.insert(tree.theRoot, "Squirtle", 0);
	tree.insert(tree.theRoot, "Ivysaur", 0);
	tree.insert(tree.theRoot, "Bulbasaur", 0);
	tree.insert(tree.theRoot, "Abra", 0);

	// Make the copy of the tree
	BinTree* treeCopy = tree.copy();

	// Delete Squirtle and reprint the tree 
	cout << "Deleting Squirtle:\n";
	tree.remove(tree.theRoot, "Squirtle");
	tree.inOrder(tree.theRoot);
	cout << endl;

	// Delete Meowth and reprint the tree 
	cout << "Deleting Meowth:\n";
	tree.remove(tree.theRoot, "Meowth");
	tree.inOrder(tree.theRoot);
	cout << endl;

	// Delete Jynx and print the tree 
	cout << "Deleting Jynx:" << endl;
	tree.remove(tree.theRoot, "Jynx");
	tree.inOrder(tree.theRoot);
	cout << endl;

	// Print the copy of the tree using inOrder, postOrder, and preOrder processing
	cout << "Inorder traversal of copy:" << endl;
	treeCopy->inOrder(treeCopy->theRoot);
	cout << endl;

	cout << "Postorder traversal of copy:" << endl;
	treeCopy->postOrder(treeCopy->theRoot);
	cout << endl;

	
	cout << "Preorder traversal of copy:" << endl;
	treeCopy->preOrder(treeCopy->theRoot);
	cout << endl;

	return 0;
}