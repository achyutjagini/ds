#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 20

// ---------------------------- STACK DEFINITION ---------------------------- //

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

/*
void clear(stack *S)
{
    printf("Stack Cleared!\n");
    S->top = -1;
}
*/

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

// ---------------------------- END OF STACK DEFINITION ---------------------------- //

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

void infix_to_postfix(char infix_expression[], char postfix_expression[], int length)
{
    stack operator_stack;
    operator_stack.top = -1;
    int index_post = 0;

    // display_stack(operator_stack);
    // printf("Current Postfix Expression: %s\n\n", postfix_expression);

    for (int i = 0; i < length; ++i)
    {
        //printf("Input: %c\n", infix_expression[i]);

        if (infix_expression[i] == ' ')
            continue;

        else if (isOperator(infix_expression[i]))
        {
            // printf("It is an Operator!\n");
            while (!isEmpty(operator_stack) && peek(operator_stack) != '(')
            {
                if (precedence(infix_expression[i]) <= precedence(peek(operator_stack)))
                    postfix_expression[index_post++] = pop(&operator_stack);
                else
                    break;
            }
            postfix_expression[index_post] = '\0';

            push(&operator_stack, infix_expression[i]);
        }

        else if (infix_expression[i] == '(')
        {
            // printf("\'(\' detected!\n");
            push(&operator_stack, '(');
        }

        else if (infix_expression[i] == ')')
        {
            // printf("\')\' detected!\n");
            while (peek(operator_stack) != '(')
                postfix_expression[index_post++] = pop(&operator_stack);
            postfix_expression[index_post] = '\0';

            pop(&operator_stack);
        }
        else
        {
            // printf("It is an Operand!\n");
            postfix_expression[index_post++] = infix_expression[i];
        }

        // display_stack(operator_stack);
        // printf("Current Postfix Expression: %s\n\n", postfix_expression);
        // '\0' has been updated every time just to print the current postfix expression!
    }

    while (!isEmpty(operator_stack))
        postfix_expression[index_post++] = pop(&operator_stack);
    postfix_expression[index_post] = '\0';

    return;
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
    char infix_expression[100];
    char postfix_expression[100];
    postfix_expression[0] = '\0';

    printf("Enter Infix Expression: ");
    scanf(" %[^\n]", infix_expression);
    int length = strlen(infix_expression);

    infix_to_postfix(infix_expression, postfix_expression, length);

    printf("Final Postfix Expression: %s\n", postfix_expression);
    printf("Result of Postfix Expression: %d\n", evaluate_postfix(postfix_expression));
    return 0;
}

// (A + B) ^ D - E * F + (G - H) / I