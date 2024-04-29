#ifndef EVENT_H_
#define EVENT_H_

#include "list.h"
#include "types.h"

struct event {
    struct list_head evt_list;
    int time;
    void (*cb)(u32 param);
    u32 param;
};

#endif // EVENT_H_
