#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1)
		{
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Item %d inserted successfully.\n", item);
    }
}

int Delete() {
    int item;
    if (front == -1) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return item;
    }
}

int search(int item) {
    if (front == -1) {
        printf("Queue is empty. Cannot search.\n");
        return 0;
    }
    for (int i = front; i <= rear; i++) {
        if (queue[i] == item) {
            printf("Item %d found at position %d.\n", item, i - front + 1);
            return 1;
        }
    }
    printf("Item %d not found in the queue.\n", item);
    return 0;
}

void change(int oldItem, int newItem) {
    int found = 0;
    if (front == -1) {
        printf("Queue is empty. Cannot change.\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        if (queue[i] == oldItem) {
            queue[i] = newItem;
            printf("Item %d changed to %d at position %d.\n", oldItem, newItem, i - front + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Item %d not found in the queue. Cannot change.\n", oldItem);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Contents: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
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
                if (item != -1) 
				{
                    printf("Item %d deleted from the queue.\n", item);
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
