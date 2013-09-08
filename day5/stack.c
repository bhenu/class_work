#include "stack.h"

struct lnk_lst init_stack(void) {
    struct lnk_lst struct_to_return;
    struct_to_return.count = 0;
    struct_to_return.head = NULL;
    return struct_to_return;
}

void push(struct lnk_lst * LL, int value) {
    if (LL->count >= STACK_SIZE) {
        printf("error: stack is full\n");
        return;
    }
    insert(LL, value);
}

void pop(struct lnk_lst * LL, int * deleted) {
    if (LL->count < 1) {
        printf("error: stack is empty\n");
        return;
    }
    delete(LL, deleted, LL->count);
}

void show(struct lnk_lst LL) {
    struct node * current = LL.head->prev;
    printf("======================\n");
    while( LL.count > 0) {
        printf("\t%d\t\n", current->data);
        current = current->prev;
        LL.count--;
    }
    printf("======================\n");
}
