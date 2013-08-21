#include <stdio.h>

#define QSIZE 20

struct queue
{
    int elements[QSIZE]; //the array to hold the queue elements
    int count; // number of elements present in the queue
    int rear_pos; // index of the last element (should be initailised to -1)
    int front_pos; // index of the first element of the queue (should be initialised to 0)
}
/* function prototypes */
int insert(int value, struct queue * Queue);
int delete(int * deleted, struct queue * Queue);
void display(struct Queue);

int main()
{
}

/* function to do the sorting */
int qsort(struct queue * Q1, struct queue * Q2)
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
        for (i = Q1->front_pos, j = Q1->count; j > 0; j--, i = (i+1)%QSIZE)
        {
            smallest = smallest > (Q1->elements[i]) ? smallest : i;
        }

        /* delete elements till the ith element */
        while ( Q1->front_pos != i )
        {
            delete(&deleted, Q1);
            insert(deleted, Q1);
        }

        /* insert smallest element in to the other queue */
        if (Q1->front_pos == i)
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
        printf("error: queue is empty\n");
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
    printf("[HEAD] ")
    while ( Q.count > 0)
    {
        printf("[%d] ", Q.elements[Q.front_pos]);
        Q.front_pos = (Q.front_pos + 1)%QSIZE;
        Q.count--;
    }
    printf("TAIL\n");
}
