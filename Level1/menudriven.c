#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int x;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    queue[++rear] = x;
    printf("Element inserted\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
