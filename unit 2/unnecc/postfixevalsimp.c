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

//end of stack definition

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 0;
    if (operator== '*' || operator== '/' || operator== '%')
        return 1;
    if (operator== '^')
        return 2;
}

_Bool isOperator(char character)
{
    switch (character)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
        return 1;
    default:
        return 0;
    }
}
int compute_value(int op1, int op2, char operator)
{
    switch (operator)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return op1 % op2;
    case '^':
        return (int)pow(op1, op2);
    }
}
int evaluate_postfix(char postfix_expression[])
{
    stack operand_stack;
    operand_stack.top = -1;
    int operand1, operand2;
    int length = strlen(postfix_expression);

    // printf("\nPostfix Expression (tb Evaluated): %s\n", postfix_expression);
    // display_stack(operand_stack);

    for (int i = 0; i < length; ++i)
    {
        if(postfix_expression[i] == ' ')
            continue;
        // printf("\nInput: %c\n", postfix_expression[i]);
        if (isOperator(postfix_expression[i]))
        {
            // printf("It is an operator!\n");
            operand2 = pop(&operand_stack);
            operand1 = pop(&operand_stack);
            push(&operand_stack, compute_value(operand1, operand2, postfix_expression[i]));
        }
        else
        {
            // printf("It is an Operand!\n");
            push(&operand_stack, postfix_expression[i] - '0');
        }
        // display_stack(operand_stack);   
    }   
    // printf("Final Result \'%d\' Popped Out!\n\n", peek(operand_stack));
    return pop(&operand_stack);
}
int main(void)
{
    char postfix_expression[100];
    printf("Enter Postfix Expression: ");
    scanf(" %[^\n]",postfix_expression );
    printf("Result of Postfix Expression: %d\n", evaluate_postfix(postfix_expression));
    return 0;
}
