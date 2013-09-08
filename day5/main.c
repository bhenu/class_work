#include <stdio.h>
#include "lnk_list.h"
#include "stack.h"

int main(void) {
    int n = 10;
    int value, deleted;
    struct lnk_lst stack = init_stack();

    do {
        printf("## 1: push\n## 2: pop\n## 3: show\n## 0: quit\n");
        scanf("%d", &n);

        switch (n) {
            case 0: break;

            case 1: printf("enter value to push\n");
                    scanf("%d", &value);
                    push(&stack, value);
                    break;
            case 2: pop(&stack, &deleted);
                    printf("deleted: %d\n", deleted);
                    break;
            case 3: show(stack);
                    break;
            default: printf("error:wrong input\n");
                    break;
            }
        } while (n);

    return 0;
}
