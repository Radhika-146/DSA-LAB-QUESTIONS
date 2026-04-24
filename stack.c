Experiment 7: Stack
Write C program to implement the below tasks:
Q 1) Implement all stack operations using array and linked list: Push, Pop, display, peek.
  Q 2) Reverse string using stack

code 1:
 //using array  :
#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push()
{
    int x;
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else{
        printf("Enter element: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else{
        printf("Deleted element = %d\n",stack[top]);
        top--;
    }
}

void peek()
{
    if(top==-1)
        printf("Stack empty\n");
    else
        printf("Top element = %d\n",stack[top]);
}

void display()
{
    int i;
    if(top==-1)
        printf("Stack empty\n");
    else{
        for(i=top;i>=0;i--)
            printf("%d ",stack[i]);
        printf("\n");
    }
}

int main()
{
    int ch;

    do{
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: break;
            default: printf("Invalid choice");
        }

    }while(ch!=5);

    return 0;
}

//using linked list:

#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *top=NULL;

void push()
{
   int x;
   struct node *newnode;

   newnode=(struct node*)malloc(sizeof(struct node));

   printf("Enter element: ");
   scanf("%d",&x);

   newnode->data=x;
   newnode->next=top;
   top=newnode;
}

void pop()
{
   if(top==NULL)
      printf("Stack Underflow\n");
   else{
      struct node *temp=top;
      printf("Deleted element = %d\n",top->data);
      top=top->next;
      free(temp);
   }
}

void peek()
{
   if(top==NULL)
      printf("Stack empty\n");
   else
      printf("Top element = %d\n",top->data);
}

void display()
{
   struct node *temp=top;

   if(top==NULL)
      printf("Stack empty\n");
   else{
      while(temp!=NULL)
      {
         printf("%d ",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}

int main()
{
   int ch;

   do{
      printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
      scanf("%d",&ch);

      switch(ch)
      {
         case 1: push(); break;
         case 2: pop(); break;
         case 3: peek(); break;
         case 4: display(); break;
         case 5: break;
         default: printf("Invalid choice");
      }

   }while(ch!=5);

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
