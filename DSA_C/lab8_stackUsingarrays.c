#include <stdio.h>

int isFull(int top, int n)
{
    return top == n - 1;
}

int isEmpty(int top)
{
    return top == -1;
}

void push(int stack[], int *top, int n)
{
    int value;

    printf("Enter the value: ");
    scanf("%d", &value);

    if (isFull(*top, n))
    {
        printf("Overflow. Cannot push.\n");
    }

    else
    {
        *top = *top + 1;
        stack[*top] = value;
    }
}

int pop(int stack[], int *top)
{
    if (isEmpty(*top))
    {
        printf("Underflow. Cannot pop.\n");
        return -1;
    }
    else
    {
        int poppedElement = stack[*top];
        *top = *top - 1;
        return poppedElement;
    }
}

void peek(int stack[], int top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void displayStack(int stack[], int top)
{
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    if (isEmpty(top))
    {
        printf("Stack is empty\n");
    }
}

int main()
{
    int stack[100], n, option = 0, top = -1;

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    while (option != 7)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (isFull(top, n))
            {
                printf("Stack is full. Cannot push.\n");
            }
            else
            {
                push(stack, &top, n);
            }
            break;

        case 2:
            if (isEmpty(top))
            {
                printf("Stack is empty. Cannot pop.\n");
            }
            else
            {
                int poppedElement = pop(stack, &top);
                printf("Popped element: %d\n", poppedElement);
            }
            break;

        case 3:
            peek(stack, top);
            break;

        case 4:
            if (isEmpty(top))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

        case 5:
            if (isFull(top, n))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;

        case 6:
            displayStack(stack, top);
            break;

        case 7:
            printf("Exiting\n");
            break;

        default:
            printf("Please Enter a valid option\n");
        }
    }

    return 0;
}



