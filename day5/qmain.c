#include <stdio.h>
#include "lnk_list.h"
#include "queue.h"

int main(void) {
    int n = 10;
    int value, deleted;
    struct lnk_lst queue = init_queue();

    do {
        printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
        scanf("%d", &n);

        switch (n) {
            case 0: break;

            case 1: printf("enter value to insert\n");
                    scanf("%d", &value);
                    q_insert(&queue, value);
                    break;
            case 2: q_delete(&queue, &deleted);
                    printf("deleted: %d\n", deleted);
                    break;
            case 3: q_display(queue);
                    break;
            default: printf("error:wrong input\n");
                    break;
            }
        } while (n);

    return 0;
}
