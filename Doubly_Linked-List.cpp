#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Node with data %d inserted successfully.\n", data);
}

void insend(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node with data %d inserted at the beginning.\n", data);
}

void insat(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        printf("Node with data %d inserted at position %d.\n", data, position);
    } else {
        struct Node* current = head;
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position. Cannot insert at position %d.\n", position);
        } else {
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
            printf("Node with data %d inserted at position %d.\n", data, position);
        }
    }
}

void Delete(int data) {
    struct Node* current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
    } else {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
        printf("Node with data %d deleted successfully.\n", data);
    }
}

void display() {
    struct Node* current = head;
    if (current == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }
    printf("Doubly linked list contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void exitProgram() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("Exiting the program.\n");
    exit(0);
}

int main() {
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Insend (Insert at the Beginning)\n");
        printf("3. Insat (Insert at a Specific Position)\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insend(data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insat(data, position);
                break;
            case 4:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                Delete(data);
                break;
            case 5:
                display();
                break;
            case 6:
                exitProgram();
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
