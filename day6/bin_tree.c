/*
 * WARNING!
 * This is a really crapy piece of code
 * DONOT USE IT!
 */

#include "bin_tree.h"

tree init_tree(void) {
    tree tree_to_return;
    tree_to_return.head = NULL;
    return tree_to_return;
}


int inst(node * root, int value) {
    node * temp;
    if ( root->data > value) {

        if ( root->left != NULL) {
            inst(root->left, value);
        }
        else {
            /* create a node */
            temp =(node *) malloc(sizeof(node));
            temp->data = value;
            temp->left = temp->right = NULL;
            root->left = temp;
            return 1;
        }
    }
    else if ( root->data < value) {
        if ( root->right != NULL) {
            inst(root->right, value);
        }
        else {
            /* create a node */
            temp =(node *) malloc(sizeof(node));
            temp->data = value;
            temp->left = temp->right = NULL;
            root->right = temp;
            return 1;
        }
    }
    else {
        printf("duplicate value\n");
        return 0;
    }

    return 0;
}

/* wrapper function for insert */

int insert(tree * given_tree, int value) {

    node * temp;

    if ( given_tree->head == NULL) {
        /* create a node */
        temp =(node *) malloc(sizeof(node));
        temp->data = value;
        temp->right = temp->left = NULL;
        /* assign the node to head */
        given_tree->head = temp;
        return 1;
    }
    else {  // give the root to inst()
        if(inst(given_tree->head, value)) {
            return 1;
        }
    }

    return 0;
}

/* display the tree as a tree */
void tree_view(node * root, int depth) {
    int i;

    if ( depth == 0) {
        printf("[%d]\n", root->data);
    }

    else {

        for( i = 1; i < depth; i++) {
            printf("|    ");
        }

        printf("|----[%d] \n", root->data);
    }
    if ( root->left != NULL) {
        tree_view(root->left, depth +1);
    }

    if ( root->right != NULL) {
        tree_view(root->right, depth +1);
    }

}

/* Wrapper for tree_view */
void display(node * root) {
    tree_view(root, 0);
}

/* delete function */

int del(node * target, node * parent) {
	if ( target->left != NULL && target->right != NULL) {
		node * IS = target->right;
		
		while ( IS->left != NULL) {
			parent = IS;
			IS = parent->left;
		}
		
		target->data = IS->data;
		target = IS;
	}
	if (target->left == NULL && target->right == NULL) {
		if (parent->left == target)
			parent->left = NULL;
		else
			parent->right = NULL;
			
		free(target);
		return 1;
	}
	if (target->left != NULL && target->right == NULL) {
		if ( parent->left == target)
			parent->left = target->left;
		else
			parent->right = target->left;
		
		free(target);
		return 1;
	}
	if (target->right != NULL && target->left == NULL) {
		if ( parent->left == target)
			parent->left = target->right;
		else
			parent->right = target->right;
		
		free(target);
		return 1;
	}
	
	return 0;
}

void search(node * root, int value) {
	if (root->data == value) {
		del(root, NULL);
		return;
	}
	else if ( root->left != NULL && root->left->data == value) {
		del(root->left, root);
		return;
	}
	else if ( root->right != NULL && root->right->data == value) {
		del(root->right, root);
		return;
	}
	else if ( root->right != NULL && root->right->data != value) {
		search(root->right, value);
	}
	else if ( root->left != NULL && root->left->data != value) {
		search(root->left, value);
	}
	return;
}

/* wrapper function */
int delete(tree * given_tree, int value) {
	search(given_tree->head, value);
	return 1;
}
