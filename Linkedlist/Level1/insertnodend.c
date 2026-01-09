#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert at end
struct Node* insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    // Traverse to last node
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
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

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    display(head);

    return 0;
}
