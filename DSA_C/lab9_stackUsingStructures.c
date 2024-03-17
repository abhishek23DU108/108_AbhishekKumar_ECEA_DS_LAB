#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100 

struct Stack {
    int data[MaxSize];
    int top;
};

// Initialize an empty stack
void createStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MaxSize - 1) {
        printf("Error: Stack is full!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Error: Stack is empty!\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void displayStack(struct Stack* stack) {
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack myStack;
    createStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    displayStack(&myStack);

    printf("Popped element: %d\n", pop(&myStack));
    displayStack(&myStack);

    return 0;
}