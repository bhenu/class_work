#include "queue.h"

struct lnk_lst init_queue(void) {
    struct lnk_lst struct_to_return;
    struct_to_return.count = 0;
    struct_to_return.head = NULL;
    return struct_to_return;
}

void q_insert(struct lnk_lst * LL, int value) {
    if (LL->count >= QUEUE_SIZE) {
        printf("error: queue is full\n");
        return;
    }
    insert(LL, value);
}

void q_delete(struct lnk_lst * LL, int * deleted) {
    if (LL->count < 1) {
        printf("error: queue is empty\n");
        return;
    }
    delete(LL, deleted, 1);
}

void q_display(struct lnk_lst LL) {
    struct node * current = LL.head->prev;
    printf("[HEAD]");

    int i = 1;
    while( i <= LL.count ) {
        printf(" [%d] ", current->data);
        current = current->prev;
        LL.count--;
    }
    printf("[TAIL]\n");
}
