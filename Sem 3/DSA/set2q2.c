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

// Function to create a circular linked list with n nodes
struct Node *createCircularLinkedList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 1; i <= n; i++)
    {
        newNode = createNode(i);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp->next = head; // Make the list circular
    return head;
}

// Function to solve the Josephus problem using circular linked list
int josephus(struct Node *head, int k)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != temp)
    { // Only one node remains in the list
        // Move to the k-th node
        for (int count = 1; count < k; count++)
        {
            prev = temp;
            temp = temp->next;
        }

        // Remove the k-th node
        printf("Person at position %d is eliminated.\n", temp->data);
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }

    return temp->data; // The last remaining node
}

// Main function
int main()
{
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    struct Node *head = createCircularLinkedList(n);
    int lastPerson = josephus(head, k);

    printf("The last person remaining is at position %d\n", lastPerson);
    return 0;
}