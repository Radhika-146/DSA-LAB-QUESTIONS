#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void createList();
void display();
void insertBeginning();
void insertEnd();
void insertPosition();
void deleteBeginning();
void deleteEnd();
void deletePosition();
void search();

int main() {

    int choice;

    while (1) {
        printf("\n\n----- MENU -----\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Search Element\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: createList();
                break;

        case 2: display();
                break;

        case 3: insertBeginning();
                break;

        case 4: insertEnd();
                break;

        case 5: insertPosition();
                break;

        case 6: deleteBeginning();
                break;

        case 7: deleteEnd();
                break;

        case 8: deletePosition();
                break;

        case 9: search();
                break;

        case 10: exit(0);

        default: printf("Invalid Choice!");
        }
    }

    return 0;
}

void createList() {

    int n, i, value;
    struct Node *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("List Created Successfully!");
}

void display() {

    struct Node *temp = start;

    if (start == NULL) {
        printf("List is Empty!");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

void insertBeginning() {

    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = start;

    start = newNode;

    printf("Inserted at Beginning!");
}

void insertEnd() {

    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    }
    else {
        temp = start;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted at End!");
}

void insertPosition() {

    struct Node *newNode, *temp;
    int value, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertBeginning();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;

    temp = start;

    for (i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid Position!");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at Position %d!", pos);
}

void deleteBeginning() {

    struct Node *temp;

    if (start == NULL) {
        printf("List is Empty!");
        return;
    }

    temp = start;
    start = start->next;

    free(temp);

    printf("First Node Deleted!");
}

void deleteEnd() {

    struct Node *temp, *prev;

    if (start == NULL) {
        printf("List is Empty!");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Last Node Deleted!");
        return;
    }

    temp = start;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last Node Deleted!");
}

void deletePosition() {

    struct Node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (start == NULL) {
        printf("List is Empty!");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = start;

    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == NULL) {
            printf("Invalid Position!");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);

    printf("Node Deleted from Position %d!", pos);
}

void search() {

    struct Node *temp = start;
    int key, pos = 1, flag = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {

        if (temp->data == key) {
            printf("Element Found at Position %d", pos);
            flag = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if (flag == 0)
        printf("Element Not Found!");
}
