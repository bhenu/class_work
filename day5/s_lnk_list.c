#include "s_lnk_list.h"

int insert(struct lnk_lst * LL, int value) {
    if (LL->count >= SIZE ) {
        printf("error: List too long\n");
        return -1;
    }
    else if (LL->count == 0) {
        struct node * new_node;
        new_node = malloc(sizeof(struct node)); /* create new node */
        new_node->data = value;                 /* insert the value */
        LL->head = new_node->next = new_node; /* point next previous to itself and assign that to the head pointer */
        (LL->count)++; /* increment the counter */
        return LL->count;
    }
    else {
        struct node * new_node;
        new_node = malloc (sizeof(struct node));  /* create new node */
        new_node->data = value;                   /* insert the value */

        /* get the last node of the list */
        struct node * current = LL->head;
        while ( current->next != LL->head) {
            current = current->next;
        }

        /* declare temporary variables */
        struct node * last_node = current;
        struct node * first_node = LL->head;

        /* assign the pointers */
        last_node->next = new_node;
        new_node->next = first_node;
        LL->count++;
        return LL->count;
    }
}

int sorted_insert(struct lnk_lst * LL, int value) {
    if (LL->count >= SIZE ) {
        printf("error: List too long\n");
        return -1;
    }
    else if (LL->count == 0) {
        struct node * new_node;
        new_node = malloc(sizeof(struct node)); /* create new node */
        new_node->data = value;                 /* insert the value */
        LL->head = new_node->next = new_node; /* point next previous to itself and assign that to the head pointer */
        (LL->count)++; /* increment the counter */
        return LL->count;
    }
    else {

        /* Assuming the list is in ascending order
         * find the first element larger than given element
         * store that position
         * insert before that position
         * if end is reached then insert at the end
         */


        /* find the first element larger than given element */
        struct node * current = LL->head;
        int position = 1;
        do {
            if ( current->data == value) {
                printf("data: %d, value: %d\n", current->data, value);
                return -1;
            }
            else if ( current->data < value) {
                printf("data: %d, value: %d #break\n ", current->data, value);
                break;
            }
            else {
                current = current->next;
                position++;
                printf("data: %d, value: %d #continue\n", current->data, value);
                printf("position: %d\n", position);
            }
        }while ( current != LL->head);


        /* creat new node */
        struct node * new_node;
        new_node = malloc (sizeof(struct node));  /* create new node */
        new_node->data = value;                   /* insert the value */

        /* get current node */
        struct node * current_node = LL->head;

        while (position > 0) {
            current_node = current_node->next;
            position--;
        }

        /* declare temporary variables */
        struct node * prev_node = current_node;
        struct node * next_node = current_node->next;

        /* assign the pointers */
        prev_node->next = new_node;
        new_node->next = next_node;
        LL->count++;
        return position;
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

        /* go to the index just before position */
        prev_node = LL->head;

        while (position > 2) {
            prev_node = prev_node->next;
            position--;
        }

        current_node = prev_node->next;
        next_node = current_node->next;

        /* address assignment */
        prev_node->next = next_node;

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

struct lnk_lst init_lnk_lst(void) {
    struct lnk_lst struct_to_return;
    struct_to_return.count = 0;
    struct_to_return.head = NULL;
    return struct_to_return;
}
