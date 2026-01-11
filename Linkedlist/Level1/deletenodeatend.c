#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Delete node from end
struct Node* deleteEnd(struct Node *head) {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // If only one node
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;   // Remove last node
    free(temp);

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

    // Delete from end
    head = deleteEnd(head);

    printf("List after deleting last node:\n");
    display(head);

    return 0;
}
