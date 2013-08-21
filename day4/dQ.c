#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QSIZE 20
#define FRONT 1
#define REAR 2

/* structure to hold the priority queue */
static struct Dqueue
{
    int elements[QSIZE];
    int count, front_pos, rear_pos;
};

/* prototype definition for queue operations */
int insert(int, int, struct Dqueue *);
int delete(int, int *, struct Dqueue *);
void display(struct Dqueue);

/* ############################  MAIN  ############################## */

int main(void)
{
    /* initialise rear queue */
    struct Dqueue Q1;
    Q1.rear_pos = -1;
    Q1.front_pos = 0;
    Q1.count = 0;

    int n = 5;
    int value, deleted, side;

    printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
    scanf("%d", &n);
    while(n != 0)
        {
            switch(n)
            {
                case 1:
                        printf("Enter the value(integer type) to insert\n");
                        scanf("%d", &value);
                        printf("where do you want to insert? %d: front, %d: rear\n", FRONT, REAR);
                        scanf("%d", &side);
                        insert(side, value, &Q1);
                        break;
                case 2:
                        printf("From which side do you want to delete? %d: front, %d: rear\n", FRONT, REAR);
                        scanf("%d", &side);
                        delete(side, &deleted, &Q1);
                        printf("deleted from queue: %d\n", deleted);
                        break;
                case 3: display(Q1);
                        break;
                default:
                        printf("error: wrong input.\n");
                        break;
            }

            printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
            scanf("%d", &n);
        }

    return 0;
}

/* definition of display */
void display(struct Dqueue Q)
{
    printf("[HEAD] ");
    while ( Q.count > 0)
    {
        printf("[%d] ", Q.elements[Q.front_pos]);
        Q.front_pos = (Q.front_pos + 1 )%QSIZE;
        Q.count--;
    }
    printf("[TAIL]\n");
}

/* definition of insert */
int insert(int side, int value, struct Dqueue *Q)
{
    if (Q->count >= QSIZE)
    {
        printf("error: queue is full\n");
        return 0;
    }
    else if(side == REAR)
    {
        Q->rear_pos = (Q->rear_pos + 1)%QSIZE;
        Q->elements[Q->rear_pos] = value;
        Q->count++;
        return 1;
    }
    else if (side == FRONT)
    {
        Q->front_pos = (Q->front_pos - 1)<0? (QSIZE - 1) : (Q->front_pos - 1);
        Q->elements[Q->front_pos] = value;
        Q->count++;
        return 1;
    }
    else
    {
        printf("error: wrong input\n");
        return 0;
    }
}

/* definition of delete */
int delete(int side, int *deleted, struct Dqueue *Q)
{
    if (Q->count <= 0)
    {
        printf("error: queue is empty\n");
        return 0;
    }
    else if(side == REAR)
    {
        *deleted = Q->elements[Q->rear_pos];
        Q->rear_pos = (Q->rear_pos - 1) < 0 ? (QSIZE - 1) : (Q->rear_pos - 1);
        Q->count--;
        return 1;
    }
    else if (side == FRONT)
    {
        *deleted = Q->elements[Q->front_pos];
        Q->front_pos = (Q->front_pos + 1)%QSIZE;
        Q->count--;
        return 1;
    }
    else
    {
        printf("error: wrong input\n");
        return 0;
    }
}
