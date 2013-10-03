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

// wrapper function for insert

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

void display(node * root) {
    tree_view(root, 0);
}
