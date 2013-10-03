#include <stdio.h>
#include "bin_tree.h"

int main(void) {
    int n = 10;
    int value;
    tree tree1 = init_tree();

    do {
        printf("## 1: insert\n## 2: delete\n## 3: display\n## 0: quit\n");
        scanf("%d", &n);

        switch (n) {
            case 0: break;

            case 1: printf("enter value to insert\n");
                    scanf("%d", &value);
                    insert(&tree1, value);
                    break;
            case 2:	printf("enter value to delete\n");
                    scanf("%d", &value);
                    delete(&tree1, value);
                    break;
            case 3: display(tree1.head);
                    break;
            default: printf("error:wrong input\n");
                    break;
            }
        } while (n);

    return 0;
}
