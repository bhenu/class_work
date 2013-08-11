#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QSIZE 20

/* structure to hold the priority queue */
static struct Pqueue
{
    struct element
    {
        int value;
        int priority;
    } e[QSIZE];

    int rear_pos;
};

/* prototype definition for queue operations */
int insert(int, int, struct Pqueue *);
int delete(int *, struct Pqueue *);
void display(struct Pqueue);

/* ############################  MAIN  ############################## */

int main(void)
{
    /* initialise rear queue */
    struct Pqueue Q1;
    Q1.rear_pos = -1;

    int n = 5;
    int value, priority, deleted;

    while(n != 0)
        {
            printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
            scanf("%d", &n);
            switch(n)
            {
                case 1:
                        printf("Enter the value(integer type) to insert\n");
                        scanf("%d", &value);
                        printf("Enter its priority (also integer type)\n");
                        scanf("%d", &priority);
                        insert(value, priority, &Q1);
                        break;
                case 2:
                        delete(&deleted, &Q1);
                        printf("deleted from queue: %d\n", deleted);
                        break;
                case 3: display(Q1);
                        break;
                default:
                        printf("error: wrong input.\n");
                        break;
            }
        }

    return 0;
}

/* definition of display */
void display(struct Pqueue Q)
{
    int i;

    printf("Queue [value | priority]: \n");

    for (i = Q.rear_pos; i > -1; i--)
        printf("[ %d | %d ] ", Q.e[i].value, Q.e[i].priority);

    printf("\n");

}

/* definition of insert */
int insert(int value, int priority, struct Pqueue *Q)
{
    if( Q->rear_pos >= QSIZE)
    {
        printf("error: Queue is full!\n");
        return 0;
    }
    else
    {
        Q->e[++(Q->rear_pos)].value = value;
        Q->e[Q->rear_pos].priority = priority;

        return 1;
    }
}

/* definition of delete */
int delete(int *deleted, struct Pqueue *Q)
{
    int i, current;
    for ( i = 0, current = 0; i <= Q->rear_pos; i++)
        current = (Q->e[i].priority) > (Q->e[current].priority) ? i : current;

    *deleted = (Q->e[current].value);

    while ( current < Q->rear_pos)
    {
        Q->e[current] = Q->e[current+1];
        current++;
    }

    Q->rear_pos--;
    return 1;
}


