Q 2) Write a menu driven program for all the operations in case of singly circular linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Reversing a linked list
i)	Traversing/ Display of linked list

code:

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = start;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(START)\n");
}


void insert_begin() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (start == NULL) {
        start = newnode;
        newnode->next = start;
    } else {
        temp = start;
        while (temp->next != start)
            temp = temp->next;

        temp->next = newnode;
        start = newnode;
        temp=start;
    }
}
void insert_end() {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (start == NULL) {
        start = newnode;
        newnode->next = start;
    } else {
        temp = start;
        while (temp->next != start)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = start;
    }
}


void insert_pos() {
    int pos, i = 1;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        insert_begin();
        return;
    }

    temp = start;
    while (i < pos - 1 && temp->next != start) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void delete_begin() {
    struct node *temp, *last;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        temp = start;
        last = start;

        while (last->next != start)
            last = last->next;

        start = start->next;
        last->next = start;
        free(temp);
    }
}


void delete_end() {
    struct node *temp, *prev;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        temp = start;
        while (temp->next != start) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = start;
        free(temp);
    }
}


void delete_pos() {
    int pos, i = 1;
    struct node *temp, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    temp = start;
    while (i < pos && temp->next != start) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    free(temp);
}


void search() {
    int key, pos = 1, found = 0;
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    do {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != start);

    if (!found)
        printf("Element not found\n");
}

// Reverse list
void reverse() {
    struct node *prev = NULL, *current, *next, *last;

    if (start == NULL || start->next == start)
        return;

    current = start;
    last = start;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != start);

    start->next = prev;
    start = prev;
}

// Main
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
        printf("7. Search Element\n");
        printf("8. Reverse List\n");
        printf("9. Display List\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: search(); break;
            case 8: reverse(); break;
            case 9: display(); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
