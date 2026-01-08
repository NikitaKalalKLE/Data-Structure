#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *temp = head;
    struct Node *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Search element */
void searchElement(struct Node *head, int key) {
    int position = 1;
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

/* Display list */
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int key;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    display(head);

    printf("Enter element to search: ");
    scanf("%d", &key);

    searchElement(head, key);

    return 0;
}
