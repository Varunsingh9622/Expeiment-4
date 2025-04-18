#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    struct Node *head;
} Stack;

Stack *createHead(void)
{
    Stack *l;
    l = (Stack *)malloc(sizeof(Stack));
    l->head = NULL;
    return (l);
}

void push(Stack *l, int v)
{
    Node *n;
    n = (Node *)malloc(sizeof(Node));
    n->value = v;
    if (l->head == NULL)
    {
        n->next = NULL;
        l->head = n;
    }
    else
    {
        n->next = l->head;
        l->head = n;
    }
}

void pop(Stack *l)
{
    Node *t;
    t = l->head;
    if (t != NULL)
    {
        printf(" %d popped from the stack", t->value);
        l->head = t->next;
    }
    else
    {
        printf(" No value in the stack to pop.\n");
    }
    free(t);
}

void peep(Stack *l)
{
    if (l->head != NULL)
    {
        printf("%d\n", l->head->value);
    }
    else
    {
        printf("No value in stack");
    }
}

void main()
{
    Stack *ls;
    int value, i, t, option = 9;
    clrscr();
    ls = createHead();
    while (1)
    {
        printf("\nSelect one of the Operations: 1. Push, 2. Peep, 3. Pop or 0 to Exit : ");
        scanf("%d", &option);
        if (option == 0)
        {
            break;
        }
        switch (option)
        {
        case 1:
            printf("\nEnter value to Push into Stack: ");
            scanf("%d", &value);
            push(ls, value);
            printf("\n%d pushed into the stack.\n", value);
            break;

        case 2:
            printf("\nThe first value in stack is: ");
            peep(ls);
            break;

        case 3:
            printf("\nPerforming pop operation on stack: ");
            pop(ls);
            break;

        default:
            printf("\nPlease select one of the given options.");
            break;
        };
    }
}
