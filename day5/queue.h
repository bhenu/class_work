#include <stdio.h>
#include "lnk_list.h"

#ifndef QUEUE_H
#define QUEUE_H

    #define QUEUE_SIZE 20

    struct lnk_lst init_queue(void);
    void q_insert(struct lnk_lst * queue, int value);
    void q_delete(struct lnk_lst * queue, int * deleted);
    void q_display(struct lnk_lst queue);

#endif
