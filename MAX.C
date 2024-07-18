

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

int stack[MAX];
int top = -1,i;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("\n Stack overflow\n");
    } else {
        stack[++top] = value;
        printf("\n %d pushed onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("\n Stack underflow\n");
    } else {
        printf("\n %d popped from the stack\n", stack[top--]);
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("\n Stack is empty....!");
    } else {
        printf("\n Stack elements:");
        for ( i = top; i >= 0; i--) {
            printf(" %d ", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    clrscr();

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Enter the value to push : ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Invalid choice\n");
        }
    }

    return 0;
}
