#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Recursive function to reverse
struct Node* reverseRecursive(struct Node *head) {
    // Base case: empty list or only one node
    if (head == NULL || head->next == NULL)
        return head;

    // Reverse remaining list
    struct Node *newHead = reverseRecursive(head->next);

    // Fix current node
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Display list
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
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
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal List:\n");
    display(head);

    // Reverse list recursively
    head = reverseRecursive(head);

    printf("\nReversed List:\n");
    display(head);

    return 0;
}
