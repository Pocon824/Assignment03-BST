#pragma once

//Structure for a BST Node
typedef struct BSTNode {
	char charData;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNODE;

int countNodes(BSTNODE*);
void inOrderTraverseBST(BSTNODE*);
void preOrderTraverseBST(BSTNODE*);
void postOrderTraverseBST(BSTNODE*);
BSTNODE* insertBSTData(BSTNODE*, char);
int getBSTHeight(BSTNODE*);
BSTNODE* createBSTNode(char);
void freeBST(BSTNODE*);