#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Insert at given position
struct Node* insertAtPosition(struct Node *head, int data, int pos) {
    struct Node *newNode, *temp = head;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Insert at beginning
    if(pos == 1) {
        newNode->next = head;
        return newNode;
    }

    // Traverse to (pos-1)th node
    for(i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if(temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display list
void display(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create list
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Original List:\n");
    display(head);

    printf("Enter data to insert: ");
    scanf("%d", &data);

    printf("Enter position: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, data, pos);

    printf("List after insertion:\n");
    display(head);

    return 0;
}
