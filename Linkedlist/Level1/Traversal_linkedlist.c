#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

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

    // Traversing the linked list
    printf("Linked List elements are:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
