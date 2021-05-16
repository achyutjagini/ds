#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 20
typedef struct stack
{
    int array[MAX];
    int top;
} stack;

_Bool isEmpty(stack S)
{
    if (S.top == -1)
        return 1;
    else
        return 0;
}

_Bool isFull(stack S)
{
    if (S.top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(stack *S, int element)
{
    if (isFull(*S))
    {
        printf("Push Unsuccessful: Stack Overflow.\n");
        return;
    }

    S->top += 1;
    S->array[S->top] = element;
    //printf("Element '%d' Successfully Pushed!\n", element);
}

int pop(stack *S)
{
    if (isEmpty((*S)))
    {
        printf("Pop Unsuccessful: Stack Underflow.\n");
        return 0;
    }
    //printf("Element '%d' Successfully Popped!\n", S->array[S->top]);
    S->top -= 1;
    return S->array[(S->top + 1)];
}
int peek(stack S)
{
    if (isEmpty(S))
    {
        printf("Error: Stack Empty.\n");
        return 0;
    }
    return S.array[S.top];
}

void display_stack(stack S)
{
    if (isEmpty(S))
    {
        printf("Empty Stack!\n");
        return;
    }

    printf("Your Stack:\n");
    for (int i = S.top; i >= 0; --i)
    {
        if (i == S.top)
            printf("%d <- TOP\n", S.array[i]);
        else
            printf("%d\n", S.array[i]);
    }
}
