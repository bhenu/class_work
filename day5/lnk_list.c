#include "lnk_list.h"

int insert(struct lnk_lst * LL, int value) {
    if (LL->count >= SIZE ) {
        printf("error: List too long\n");
        return -1;
    }
    else if (LL->count == 0) {
        struct node * new_node;
        new_node = malloc(sizeof(struct node)); /* create new node */
        new_node->data = value;                 /* insert the value */
        LL->head = new_node->next = new_node->prev = new_node; /* point next previous to itself and assign that to the head pointer */
        (LL->count)++; /* increment the counter */
        return LL->count;
    }
    else {
        struct node * new_node;
        new_node = malloc (sizeof(struct node));  /* create new node */
        new_node->data = value;                   /* insert the value */

        /* get the last node of the list */
        struct node * last_node = (*(LL->head)).prev;
        struct node * first_node = LL->head;

        /* assign the pointers */
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = first_node;
        first_node->prev = new_node;
        LL->count++;
        return LL->count;
    }
}

int delete(struct lnk_lst * LL, int * deleted, int position)
{
    if (LL->count < 1) {
        printf("error: list is empty!\n");
        return -1;
    }
    if (position > LL->count || position < 1) {
        printf("error: invalid position\n");
        return -1;
    }
    else {
        struct node * next_node;
        struct node *  current_node;
        struct node *  prev_node;

        /* go to the position */
        current_node = LL->head;

        while (position > 1) {
            current_node = current_node->next;
            position--;
        }

        prev_node = current_node->prev;
        next_node = current_node->next;

        /* address assignment */
        prev_node->next = next_node;
        next_node->prev = prev_node;

        if ( current_node == LL->head) {
            LL->head = current_node->next;
        }

        *deleted = current_node->data;
        free(current_node);
        LL->count--;

        return LL->count;
    }
}

void display(struct lnk_lst LL) {
    struct node * current;
    int i = LL.count;

    if (LL.count == 0 ) {
        printf("Aw the list is empty!\n");
        return;
    }
    else {
        printf("[HEAD] ");
        current = LL.head;

        while ( i > 0) {
            printf("[%d] ", current->data);
            current = current->next;
            i--;
        }

        printf("[TAIL]\n");
        return;
    }
}

void sdelete(struct lnk_lst * LL, int value) {
    int count = 1, deleted;
    struct node *current = LL->head;
    while(count <= LL->count) {
        if ( current->data == value) {
            delete( LL, &deleted, count);
            printf("value: %d deleted: %d\n", value, deleted);
            count = 1;
            current = LL->head;
        }
        else {
            current = current->next;
            count++;
        }
    }
}
