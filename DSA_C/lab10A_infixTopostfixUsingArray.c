#include <stdio.h>
#include <string.h>


int isEmpty(int top) 
{
    return (top == -1);
}

int isFull(int top, int length) 
{
    return (top == length - 1);
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

void push(char stack[], int *top, int length, char val) 
{
    if (isFull(*top, length)) 
    {
        printf("Stack Overflow\n");
    } 
    
    else 
    {
        (*top)++;
        stack[*top] = val;
    }
}

char pop(char stack[], int *top) 
{
    if (isEmpty(*top)) 
    {
        printf("Stack Underflow\n");
        return -1; // Indicate an error
    } 
    
    else 
    {
        char poppedElement = stack[*top];
        (*top)--;
        return poppedElement;
    }
}

void infixToPostfix(char *infix, char postfix[], int *top) 
{
    int i = 0;
    int j = 0;
    int length = strlen(infix);
    char stack[100];

    while (i < length) 
    {
        if (!isOperator(infix[i]))
         {
            postfix[j] = infix[i];
            i++;
            j++;
        } 
        
        else 
        {
            if (precedence(infix[i]) > precedence(stack[*top])) 
            {
                push(stack, top, 100, infix[i]);
                i++;
            } 
            
            else 
            {
                postfix[j] = pop(stack, top);
                j++;
            }
        }
    }

    while (!isEmpty(*top)) 
    {
        postfix[j] = pop(stack, top);
        j++;
    }

    postfix[j] = '\0'; 
}

int main() 
{
    int top = -1;
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix, &top);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
