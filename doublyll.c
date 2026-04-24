#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

//insert at beginning
void insert_begin() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

//insert at end
void insert_end() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;

    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

//insert at position
void insert_pos() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    struct node *temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

//delete from beginning
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

//delete from end
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

//delete from position
void delete_pos() {
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

//show linked list
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
