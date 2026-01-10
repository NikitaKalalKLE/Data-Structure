#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Delete node from beginning
struct Node* deleteBeginning(struct Node *head) {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    temp = head;          // Store old head
    head = head->next;    // Move head to next node
    free(temp);           // Free old head

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
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
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

    // Delete from beginning
    head = deleteBeginning(head);

    printf("List after deleting first node:\n");
    display(head);

    return 0;
}
