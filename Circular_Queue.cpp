#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insert(int item) {
    if (isFull()) {
        printf("Circular Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        circularQueue[rear] = item;
        printf("Item %d inserted successfully.\n", item);
    }
}

int Delete() {
    int item;
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot delete.\n");
        return -1;
    } else {
        item = circularQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return item;
    }
}

int search(int item) {
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot search.\n");
        return 0;
    }
    int i = front;
    do {
        if (circularQueue[i] == item) {
            printf("Item %d found at position %d.\n", item, (i - front + 1) % MAX_SIZE);
            return 1;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("Item %d not found in the Circular Queue.\n", item);
    return 0;
}

void change(int oldItem, int newItem) {
    int found = 0;
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot change.\n");
        return;
    }
    int i = front;
    do {
        if (circularQueue[i] == oldItem) {
            circularQueue[i] = newItem;
            printf("Item %d changed to %d at position %d.\n", oldItem, newItem, (i - front + 1) % MAX_SIZE);
            found = 1;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    if (!found) {
        printf("Item %d not found in the Circular Queue. Cannot change.\n", oldItem);
    }
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }
    int i = front;
    printf("Circular Queue Contents: ");
    do {
        printf("%d ", circularQueue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    int choice, item, oldItem, newItem;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = Delete();
                if (item != -1) {
                    printf("Item %d deleted from the Circular Queue.\n", item);
                }
                break;
            case 3:
                printf("Enter the item to search: ");
                scanf("%d", &item);
                search(item);
                break;
            case 4:
                printf("Enter the item to change: ");
                scanf("%d", &oldItem);
                printf("Enter the new item: ");
                scanf("%d", &newItem);
                change(oldItem, newItem);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
