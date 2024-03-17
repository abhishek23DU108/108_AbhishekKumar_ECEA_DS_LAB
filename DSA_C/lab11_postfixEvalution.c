#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

int isFull(struct stack *ptr)
{
    return (ptr->top == ptr->size - 1);
}

int stackTop(struct stack *ptr)
{
    return ptr->top;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int poppedElement = ptr->arr[ptr->top];
        ptr->top--;
        return poppedElement;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int postfixEvaluation(char *postfix)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = -1;
    stack->size = 100;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (!isOperator(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (postfix[i])
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            case '^':
                push(stack, pow(operand1,operand2));
                break;
            }
        }
    }

    int result = pop(stack);
    free(stack->arr);
    free(stack);
    return result;
}

int main()
{
    printf("Enter a postfix expression: ");
    char postfix[100];
    scanf("%s", postfix);

    int result = postfixEvaluation(postfix);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}





