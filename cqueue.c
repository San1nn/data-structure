#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int que[SIZE];
int front = 0, rear = 0;

void enque(int item);
int deque();
int search(int item);

int main() {
    int option, item, ans;
    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Item: ");
                scanf("%d", &item);
                enque(item);
                break;

            case 2:
                item = deque();
                printf("Item = %d \n", item);
                break;

            case 3:
                printf("Item to search: ");
                scanf("%d", &item);
                ans = search(item);
                if(ans != 0)
                    printf("%d found at position %d \n", item, ans);
                else
                    printf("%d not found \n", item);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(1);
    return 0;
}

void enque(int item) {
    int t = (rear + 1) % SIZE;
    if (t == front) {
        printf("Queue is full\n");
        exit(1);
    } else {
        que[rear] = item;
        rear = t;  // Move rear to the next position
    }
}

int deque() {
    if (front == rear) {
        printf("Queue is empty\n");
        exit(2);
    }
    front = (front + 1) % SIZE; // Move front to the next position
    return que[front]; // Return the dequeued item
}

int search(int item) {
    int t = (front + 1) % SIZE; // Start searching from the next position of front
    while (t != rear) { // Loop until we reach rear
        if (que[t] == item) {
            return t; // Return the position of the found item
        }
        t = (t + 1) % SIZE; // Move to the next position
    }
    return 0; // Item not found
}

