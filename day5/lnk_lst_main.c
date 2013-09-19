#include <stdio.h>
#include "lnk_list.h"

int main(void) {
    int n = 10;
    int value, deleted, position;
    struct lnk_lst lnk_lst1 = init_lnk_lst();

    do {
        printf("## 1: insert\n## 2: delete\n## 3: display\n## 4: insert after\n## 5: insert before\n## 0: quit\n");
        scanf("%d", &n);

        switch (n) {
            case 0: break;

            case 1: printf("enter value to insert\n");
                    scanf("%d", &value);
                    printf("inserted at position: %d\n" ,insert(&lnk_lst1, value));
                    break;
            case 2: delete(&lnk_lst1, &deleted, lnk_lst1.count);
                    printf("deleted: %d\n", deleted);
                    break;
            case 3: display(lnk_lst1);
                    break;
            case 4: printf("enter value and position of insertion seperated by a space\n");
                    scanf("%d%d", &value, &position);
                    printf("inserted on position: %d\n" ,insert_after(&lnk_lst1, value, position));
                    break;
            case 5: printf("enter value and position of insertion seperated by a space\n");
                    scanf("%d%d", &value, &position);
                    printf("inserted on position: %d\n" ,insert_before(&lnk_lst1, value, position));
                    break;
            default: printf("error:wrong input\n");
                    break;
            }
        } while (n);

    return 0;
}
