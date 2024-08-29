#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node **top, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to peek the top element of the stack
int peek(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *top = NULL;
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to push: ");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            data = pop(&top);
            if (data != -1)
            {
                printf("%d popped from stack\n", data);
            }
            break;

        case 3:
            data = peek(top);
            if (data != -1)
            {
                printf("Top element is %d\n", data);
            }
            break;

        case 4:
            display(top);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
