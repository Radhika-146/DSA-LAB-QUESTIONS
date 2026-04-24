#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next;
};

struct Node *head=NULL,*tail=NULL;

void insertBeg(){
    int val;
    printf("Enter value: ");
    scanf("%d",&val);

    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;

    if(head==NULL){
        head=tail=newNode;
        head->next=head;
        head->prev=head;
    }
    else{
        newNode->next=head;
        newNode->prev=tail;
        head->prev=newNode;
        tail->next=newNode;
        head=newNode;
    }
}

void insertEnd(){
    int val;
    printf("Enter value: ");
    scanf("%d",&val);

    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;

    if(head==NULL){
        head=tail=newNode;
        head->next=head;
        head->prev=head;
    }
    else{
        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        head->prev=newNode;
        tail=newNode;
    }
}

void deleteBeg(){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }

    if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{
        struct Node *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void deleteEnd(){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }

    if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{
        struct Node *temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}

void display(){
    if(head==NULL){
        printf("List Empty\n");
        return;
    }

    struct Node *temp=head;

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

int main(){
    int ch;

    while(1){
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Delete Beginning");
        printf("\n4.Delete End");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                insertBeg();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
