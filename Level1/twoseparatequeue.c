#include <stdio.h>
#define MAX 5

int queue1[MAX], queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Insert into Queue 1
void enqueue1(int val) {
    if (rear1 == MAX - 1) {
        printf("Queue1 Overflow\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    queue1[++rear1] = val;
}

// Insert into Queue 2
void enqueue2(int val) {
    if (rear2 == MAX - 1) {
        printf("Queue2 Overflow\n");
        return;
    }
    if (front2 == -1) front2 = 0;
    queue2[++rear2] = val;
}

// Display Queue 1
void display1() {
    if (front1 == -1) {
        printf("Queue1 Empty\n");
        return;
    }
    for (int i = front1; i <= rear1; i++)
        printf("%d ", queue1[i]);
    printf("\n");
}

// Display Queue 2
void display2() {
    if (front2 == -1) {
        printf("Queue2 Empty\n");
        return;
    }
    for (int i = front2; i <= rear2; i++)
        printf("%d ", queue2[i]);
    printf("\n");
}

int main() {
    enqueue1(10);
    enqueue1(20);
    enqueue2(100);
    enqueue2(200);

    printf("Queue 1:\n");
    display1();

    printf("Queue 2:\n");
    display2();

    return 0;
}
