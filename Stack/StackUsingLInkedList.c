#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;
struct node *curr;

void createStack()
{
    top=NULL;
    printf("Stack created successfully \n");
}

void isEmpty()
{
    if(top==NULL)
        printf("True, Stack is empty \n");
    else
        printf("False, Stack is not empty \n");
}

void push()
{
    int data;
    curr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item to be inserted : ");
    scanf("%d",&data);
    printf("\n");
    curr->data=data;
    curr->next=NULL;
    if(top==NULL)
    {
       top=curr;
    }
    else
    {
        curr->next=top;
        top=curr;
        //top->next=NULL;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is empty \n");
    }
    else
    {
        int data;
        data=top->data;
        curr=top;
        top=top->next;
        curr->next=NULL;
        free(curr);
    }
}

void display()
{
    if(top==NULL)
        printf("Stack is empty . \n");
    else
    {
        struct node *ptr;
        ptr=top;
        printf("Stack contains : ");
        while(ptr!=NULL)
        {
            printf("-> %d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main()
 {

  int choice;
  while(1)
  {
     printf("\n\n 1. Dispaly");
     printf("\n\n 2. Create Stack ");
     printf("\n\n 3. IsEmpty ?");
     printf("\n\n 4. PUSH");
     printf("\n\n 5. POP");
     printf("\n\n 6. Exit\n\n");
     scanf("%d",&choice);

     switch(choice)
     {
     case 1:
         display();
         break;
    case 2:
        createStack();
        break;
     case 3:
        isEmpty();
        break;
     case 4:
        push();
        break;
     case 5:
        pop();
        break;
     case 6:
         exit(0);
         break;
     }
  }
 }

