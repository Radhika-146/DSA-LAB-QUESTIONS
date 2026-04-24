Experiment 7: Stack
Write C program to implement the below tasks:
Q 1) Implement all stack operations using array and linked list: Push, Pop, display, peek.
  Q 2) Reverse string using stack

code 1:
 #include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *top=NULL;

struct node *createnode(int data){
    struct node *newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void push(int data){
    struct node *newnode=createnode(data);
    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    if(top==NULL){
        printf("the list is empty\n");
    }
    else{
        struct node *temp=top;
        top=top->next;
        free(temp);
    }
}

void display(){
    struct node *temp = top;

    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element = %d\n", top->data);
    }
}

void reverse(){
    struct node *prev = NULL;
    struct node *current = top;
    struct node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    top=prev;
}

int main(){
    int choice, data;

    do{
        printf("\n STACK MENU \n");
        printf("1) Push element in stack\n");
        printf("2) Pop element from stack\n");
        printf("3) Display stack\n");
        printf("4) Peek top element\n");
        printf("5) Reverse stack\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
        }

        else if(choice == 2){
            pop();
        }

        else if(choice == 3){
            display();
        }

        else if(choice == 4){
            peek();
        }

        else if(choice == 5){
            reverse();
        }

        else if(choice == 6){
            printf("Exiting program...\n");
        }

        else{
            printf("Invalid choice\n");
        }

    }while(choice != 6);

    return 0;
}



code 2:

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], stack[100];
    int top = -1, i;

    printf("Enter string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++)
    {
        top++;
        stack[top] = str[i];
    }

    for(i = 0; i < strlen(str); i++)
    {
        str[i] = stack[top];
        top--;
    }

    printf("Reversed string: %s", str);

    return 0;
}
