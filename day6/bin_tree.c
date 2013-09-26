/* 
 * WARNING!
 * This is a really crapy piece of code 
 * DONOT USE IT! 
 */

#include "bin_tree.h"

binary_tree init_tree(void) {
	binary_tree tree_to_return;
	tree_to_return.head = NULL;
	return tree_to_return;
}


int insert(node * head, int value) {
	node * temp;
	
	if ( head == NULL) {
		/* create a node */
		temp = malloc(sizeof(node));
		temp->data = value;
		temp->right = temp->left = NULL;
		/* assign the node to head */
		head = temp;
		return 1;
	}
	else if ( head->data > value) {
		
		if ( head->left != NULL) {
			insert(head->left, value);
		}
		else {
			/* create a node */
			temp = malloc(sizeof(node));
			temp->data = value;
			temp->left = temp->right = NULL;
			head->left = temp;
			return 1;
		}
	}
	else if ( head->data < value) {
		if ( head->right != NULL) {
			insert(head->right, value);
		}
		else {
			/* create a node */
			temp = malloc(sizeof(node));
			temp->data = value;
			temp->left = temp->right = NULL;
			head->right = temp;
			return 1;
		}
	}
	else {
		printf("duplicate value\n");
		return 0;
	}
	
	return 0;
}

void tree_view(node head, int depth) {
	int i;
	
	for( i = 0; i < depth; i++) {
		printf("|    |");
	}
	
	printf("----[%d] \n", head.data);
	if ( head.left != NULL) {
		tree_view(head.left, depth +1);
	}
	else if ( head.right != NULL) {
		tree_view(head.right, depth +1);
	}
}

void display(node head) {
	tree_view(*head, 0);
}
