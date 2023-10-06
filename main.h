#ifndef TODO_H
#define TODO_H

#include <stdbool.h>

#define MAX_TASKS 100

struct Task
{
    char description[100];
    bool completed;
};

void print_menu(void);

#endif /* TODO_H */
