#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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
    return newNode;
}

void insert(int data) {
    struct Node* newNo;
	de = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Node with data %d inserted successfully.\n", data);
}

void insbegin(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
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
            current->next = newNode;
            printf("Node with data %d inserted at position %d.\n", data, position);
        }
    }
}

void Delete(int data) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
    } else {
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Node with data %d deleted successfully.\n", data);
    }
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list reversed successfully.\n");
}

int search(int data) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            printf("Node with data %d found at position %d.\n", data, position);
            return 1;
        }
        current = current->next;
        position++;
    }
    printf("Node with data %d not found in the linked list.\n", data);
    return 0;
}

void display() {
    struct Node* current = head;
    if (current == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int count() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void sort() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            if (current->data > temp->data) {
                int tempData = current->data;
                current->data = temp->data;
                temp->data = tempData;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    printf("Linked list sorted in ascending order.\n");
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
    int choice, data, position, countResult;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Insbegin (Insert at the Beginning)\n");
        printf("3. Insat (Insert at a Specific Position)\n");
        printf("4. Delete\n");
        printf("5. Reverse\n");
        printf("6. Search\n");
        printf("7. Sort\n");
        printf("8. Count\n");
        printf("9. Display\n");
        printf("10. Exit\n");
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
                insbegin(data);
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
                reverse();
                break;
            case 6:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 7:
                sort();
                break;
            case 8:
                countResult = count();
                printf("Number of nodes in the linked list: %d\n", countResult);
                break;
            case 9:
                display();
                break;
            case 10:
                exitProgram();
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
