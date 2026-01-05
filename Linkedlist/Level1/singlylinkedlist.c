#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;     // First node
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Display the linked list
    printf("\nSingly Linked List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
