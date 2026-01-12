#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Delete node at given position
struct Node* deleteAtPosition(struct Node *head, int pos) {
    struct Node *temp, *del;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Delete first node
    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return head;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

// Display linked list
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
    int n, i, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create list
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

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    printf("\nList after deletion:\n");
    display(head);

    return 0;
}
