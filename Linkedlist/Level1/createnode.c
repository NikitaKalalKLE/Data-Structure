#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert at beginning
struct Node* insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = value;
    newNode->next = head;   // link new node to old head
    head = newNode;         // update head

    return head;
}

// Function to display list
void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert nodes
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Display list
    display(head);

    return 0;
}
