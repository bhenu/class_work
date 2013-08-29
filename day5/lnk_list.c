#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
/* structure to hold the nodes of the linked list */
struct node {
	int data; 	/* node paylode */
	struct node *next;	/* address of next node */
	struct node *prev;	/* adress of previous node */
};

/* structure to hold the linked list variables */
struct lnk_lst {
	struct node * head;	/* the head pointer */
	int count;			/* no of elements in the list */
};

/* function prototypes */
int insert(struct lnk_lst * linked_list, int value); /* returns position of insertion on success and -1 on failure */
int delete(struct lnk_lst * linked_list, int * deleted, int position); /* returns position of the deleted element on success and -1 on failure */
void display(struct lnk_lst);	/* displays the linked lists */

/* ######################### MAIN LOGIC ############################# */

int main(void)
{
	struct lnk_lst LL;
	LL.count = 0;
	int value, deleted, position; 			/* variabel to store value to be
									inserted and value that is deleted*/
									
	int n = 25;						/* variable to store user input */
	
	while(n != 0)
    {
        printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
        scanf("%d", &n);
        switch(n)
        {
			case 0:
					break;
            case 1:	printf("Enter an integer to insert\n");
                    scanf("%d", &value);
                    printf("inserted %d\n", insert(&LL, value));
                    break;
            case 2: printf("enter position to delete\n");
                    scanf("%d", &position);
					delete(&LL, &deleted, position);
					printf("deleted: %d\n", deleted);
                    break;
            case 3: printf("Linked List:\n");
					display(LL);
                    break;
			default: printf("error: wrong input\n");
					break;
        }
    }
    return 0;
}

/* ###############################O################################## */

/* function definitions */
int insert(struct lnk_lst * LL, int value) {
	if (LL->count >= SIZE ) {
		printf("error: List too long\n");
		return -1;
	}
	else if (LL->count == 0) {
		struct node * new_node;
		new_node = malloc(sizeof(struct node)); /* create new node */
		new_node->data = value;			 		/* insert the value */
		LL->head = new_node->next = new_node->prev = new_node; /* point next previous to itself and assign that to the head pointer */
		(LL->count)++; /* increment the counter */
		return LL->count;		
	}
	else {
		struct node * new_node;
		new_node = malloc (sizeof(struct node));  /* create new node */
		new_node->data = value; 				  /* insert the value */
		
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

void sdelete(struct lnk_lst *LL) {
	/* search */
	/* delete */
}
