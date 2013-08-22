#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QSIZE 20
#define MAXOP 100

struct queue
{
    int elements[QSIZE]; /* the array to hold the queue elements */
    int count; /* number of elements present in the queue */
    int rear_pos; /* index of the last element (should be initailised to -1) */
    int front_pos; /* index of the first element of the queue (should be initialised to 0) */
};

/* function prototypes for queue */
int insert(int value, struct queue * Queue);
int delete(int * deleted, struct queue * Queue);
void display(struct queue);

/* auxiliary functions */
int fill_queue(struct queue *);
int getop(char [], int *, char []);

/* sort function */
int Qsort(struct queue *, struct queue *);

/* ######################### MAIN LOGIC ############################# */
int main()
{
    struct queue Q1, Q2;
    Q1.count = Q2.count = 0;
    Q1.rear_pos = Q2.rear_pos = -1;
    Q1.front_pos  = Q2.front_pos = 0;

    /* take input into queue */
    printf("Queue 1: \n");
    fill_queue(&Q1);
    printf("Queue 2: \n");
    fill_queue(&Q2);

    /* sorting algorithm */
    Qsort(&Q1, &Q2);

    display(Q2);
    return 0;
}

/* ###############################O################################## */


/* function to do the sorting */
int Qsort(struct queue * Q1, struct queue * Q2)
{
    int deleted, i, j, smallest;

    /* put content of Q2 in Q1 */
    while (delete(&deleted, Q2))
    {
        insert(deleted, Q1);
    }
    
    while ( Q1->count > 0)
    {
		
        /* find index of smallest element */
        
        for (i = Q1->front_pos, j = Q1->count, smallest = 0; j > 0; j--, i = (i+1)%QSIZE)
        {
            smallest = Q1->elements[smallest] < (Q1->elements[i]) ? smallest : i;
        }
        

        /* delete elements till the ith element */
        while ( Q1->front_pos != smallest )
        {
            delete(&deleted, Q1);
            insert(deleted, Q1);
        }

        /* insert smallest element in to the other queue */
        if (Q1->front_pos == smallest)
        {
            delete(&deleted, Q1);
            insert(deleted, Q2);
        }
    }
    return 1;
}

/* functions for queue operations */
int insert(int value, struct queue * Q)
{
    if ( Q->count >= (QSIZE - 1))
    {
        printf("error: queue is full.\n");
        return 0;
    }
    else
    {
        Q->rear_pos = (Q->rear_pos + 1)%QSIZE;
        Q->elements[Q->rear_pos] = value;
        ++Q->count;
        return 1;
    }
}

int delete(int *deleted, struct queue * Q)
{
    if ( Q->count <= 0)
    {
        return 0;
    }
    else
    {
        *deleted = Q->elements[Q->front_pos];
        Q->front_pos = (Q->front_pos + 1)%QSIZE;
        Q->count--;
        return 1;
    }
}

void display(struct queue Q)
{
    printf("[HEAD] ");
    while ( Q.count > 0)
    {
        printf("[%d] ", Q.elements[Q.front_pos]);
        Q.front_pos = (Q.front_pos + 1)%QSIZE;
        Q.count--;
    }
    printf("TAIL\n");
}

/* definition of getop function */
int getop(char string[], int *idx, char op[])
{
    char c;     /* temp variable to store current char */
    int i;

    while ((op[0] = c = string[(*idx)++]) == ' ' || c == '\t')
    /* loop through spaces */
        ;
    op[1] = '\0';

    if (!isdigit(c) && c != '.') /* not a number or decimal point */
        return 0;

    i = 0;
    if (isdigit(c))
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    if (c == '.')
        while (isdigit(op[++i] = c = string[(*idx)++]))
            ;
    op[i] = '\0';

    if(c != '\0')
        (*idx)--;

    return 1;
}


/* function to take input into the queue */
int fill_queue(struct queue *myqueue)
{
    char input[MAXOP], op[20];
    int type, indx = 0;

    printf("Enter elements of the stack [type int] seperated by a space:\n");
    fgets(input, MAXOP, stdin);

    type = getop(input, &indx, op);
    while(op[0] != '\0')
    {
        if (type)
            insert(atoi(op), myqueue);

        type = getop(input, &indx, op);
    }

    return 1;
}
