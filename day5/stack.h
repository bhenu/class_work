#include <stdio.h>
#include "lnk_list.h"

#ifndef STACK_H
#define STACK_H

    #define STACK_SIZE 20

    struct lnk_lst init_stack(void);
    void push(struct lnk_lst * stack, int value);
    void pop(struct lnk_lst * stack, int * deleted);
    void show(struct lnk_lst stack);

#endif
