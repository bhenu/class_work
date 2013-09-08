#include <stdio.h>
#include <stdlib.h>

#ifndef LNK_LIST_H
#define LNK_LIST_H

    #define SIZE 20
    /* structure to hold the nodes of the linked list */
    struct node {
        int data;   /* node paylode */
        struct node *next;  /* address of next node */
        struct node *prev;  /* adress of previous node */
    };

    /* structure to hold the linked list variables */
    struct lnk_lst {
        struct node * head; /* the head pointer */
        int count;          /* no of elements in the list */
    };


    /* function prototypes */
    int insert(struct lnk_lst * linked_list, int value); /* returns position of insertion on success and -1 on failure */
    int delete(struct lnk_lst * linked_list, int * deleted, int position); /* returns position of the deleted element on success and -1 on failure */
    void display(struct lnk_lst);   /* displays the linked lists */
    void sdelete(struct lnk_lst * linked_list, int value); /* deletes nodes with given valued nodes */

#endif
