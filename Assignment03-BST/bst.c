#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


BSTNODE* createBSTNode(char data) {
	//Malloc a new node.
	BSTNODE* newNode = (BSTNODE*)malloc(sizeof(BSTNODE));

	//Check for memory allocation errors.
	if (newNode == NULL) {
		exit(-1);
	}

	//set all values to NULL
	newNode->charData = data;
	newNode->left = NULL;
	newNode->right = NULL;

	//return the pointer of the new node.
	return newNode;
}

//Function will return the number of nodes in a tree
int countNodes(BSTNODE* tree) {

	//if the tree is empty we return 0
	if (tree == NULL) {
		return 0;
	}
	//Otherwise we add 1 and recurse down the right and left sides of the tree. Each fractal branch will eventually hit a NULL and we will add all the totals together.
	else {
		return 1 + countNodes(tree->left) + countNodes(tree->right);
	}
}

//Traversals: The only thing that changes is when you decide to print the data.

void inOrderTraverseBST(BSTNODE* tree) {
	//If tree is empty we return
	if (tree == NULL) {
		return;
	}
	
	inOrderTraverseBST(tree->left);
	printf("%c ", tree->charData);
	inOrderTraverseBST(tree->right);
}

void preOrderTraverseBST(BSTNODE* tree) {
	//if tree is empty we return
	if (tree == NULL) {
		return;
	}

	printf("%c ", tree->charData);
	preOrderTraverseBST(tree->left);
	preOrderTraverseBST(tree->right);
}

void postOrderTraverseBST(BSTNODE* tree) {
	//if tree is empty we return
	if (tree == NULL) {
		return;
	}

	postOrderTraverseBST(tree->left);
	postOrderTraverseBST(tree->right);
	printf("%c ", tree->charData);
}

//Insert a node with data into the tree. Will return the updated tree node back to you.
BSTNODE* insertBSTData(BSTNODE* tree, char data) {
	//Case: We are at the leaf we want to attatch the node too.
	//If the tree is null we know we are at the correct node and can return a new node to be attached.
	if (tree == NULL) {

		return createBSTNode(data);
	}
	//Case: We have not found an empty node to attatch the node yet, continue comparing and recursing through the tree.
	else {
		//Case: Data is greater than the current node's data, recurse right.
		if (data > tree->charData) {
			tree->right = insertBSTData(tree->right, data);
		}
		//Case: Data is less than the current node's data, recurse left.
		else if (data < tree->charData) {
			tree->left = insertBSTData(tree->left, data);
		}
		else {
			return tree;
		}
	}
	//Return the tree node after node has been inserted.
	return tree;
}

//Get the maximum height of a BST. 
int getBSTHeight(BSTNODE* tree) {

	//If the tree is empty the height is 0
	if (tree == NULL) {
		return 0;
	}

	//each time we recurse (when the tree is not NULL) we can add to the left or right height.
	int left_height = getBSTHeight(tree->left);
	int right_height = getBSTHeight(tree->right);

	//After both have reached a leaf node we return the greater height + 1 to include the current node.
	return (left_height > right_height ? left_height : right_height) + 1;
}

//Free all the memory in a BST
void freeBST(BSTNODE* tree) {
	if (tree == NULL) {
		return;
	}
	// Recursively free the left and right subtrees
	freeBST(tree->left);
	freeBST(tree->right);
	// Free the current node
	printf("Node with data %c has been freed\n", tree->charData);
	free(tree);
}
