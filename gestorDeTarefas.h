#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int priority;
    char *id;
    struct node *next;
} node;

node *createNewTask(node *list, int priority, char *id);

void listTasks(node *list, int priority);

int searchID(node *list, char *id);

node *removeTask(node *list, char *id);