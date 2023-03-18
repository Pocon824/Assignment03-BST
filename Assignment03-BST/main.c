#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_NODE_OFFSET 11
#define NUM_LETTERS_IN_ALPHABET 26
#define ASCII_A 65
#define NODE_RANGE 10

int main(void) {

	//Initialize an empty node for the tree.
	BSTNODE* tree = NULL;

	//Seed random time
	srand(time(NULL));

	//set a variable for number of nodes to include in the tree.
	int numTreeNodes = (rand() % NODE_RANGE) + MIN_NODE_OFFSET;

	for (int i = 0; i < numTreeNodes; i++) {
		char data = ASCII_A + (rand() % NUM_LETTERS_IN_ALPHABET);
		data = tolower(data);
		tree = insertBSTData(tree, data);
	}
	
	inOrderTraverseBST(tree);
	printf("\n");
	preOrderTraverseBST(tree);
	printf("\n");
	postOrderTraverseBST(tree);
	printf("\n");
	int numNodes = countNodes(tree);
	printf("%d\n", numNodes);

	int height = getBSTHeight(tree);
	printf("%d\n", height);

	printf("\n");

	freeBST(tree);
	return 0;
}