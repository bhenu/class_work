#include <stdio.h>

#define QSIZE 20

struct queue
{
    int elements[QSIZE]; //the array to hold the queue elements
    int count; // number of elements present in the queue
    int rear_pos; // index of the last element (should be initailised to -1)
    int front_pos; // index of the first element of the queue (should be initialised to 0)
}

int insert(int value, struct queue * Queue);
int delete(int * deleted, struct queue * Queue);
void display(struct Queue);

