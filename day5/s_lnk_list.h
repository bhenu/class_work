#include <stdio.h>
#include <stdlib.h>

#ifndef S_LNK_LIST_H
#define S_LNK_LIST_H

    #define SIZE 20
    /* structure to hold the nodes of the linked list */
    struct node {
        int data;   /* node paylode */
        struct node *next;  /* address of next node */
    };

    /* structure to hold the linked list variables */
    struct lnk_lst {
        struct node * head; /* the head pointer */
        int count;          /* no of elements in the list */
    };


    /* function prototypes */
    struct lnk_lst init_lnk_lst(void);                  /* returns a new linked list instance */
    int insert(struct lnk_lst * linked_list, int value); /* returns position of insertion on success and -1 on failure */
    int sorted_insert(struct lnk_lst * linked_list, int value); /* returns position of insertion on success and -1 on failure */
    int delete(struct lnk_lst * linked_list, int * deleted, int position); /* returns position of the deleted element on success and -1 on failure */
    void display(struct lnk_lst);   /* displays the linked lists */

#endif
