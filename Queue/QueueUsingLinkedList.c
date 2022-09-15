#include<stdlib.h>
#include<stdio.h>
struct node
{

    int data;
    struct node *next;
};
struct node *front,*rear;
void insert();
void delete();
void display();

void main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Wrong Choice");
                break;
        }
    }
}


void insert()
{
    struct node *ptr;
    int data;
    ptr=(struct node*)malloc(sizeof(struct node));

    if(ptr==NULL)
        printf("QUEUE OVERFLOW");
    else
    {
        printf("\nEnter the item to be inserted : ");
        scanf("%d", &data);
        ptr->data=data;
        ptr->next=NULL;
        if(front==NULL)
        {
            front=rear=ptr;
            rear=rear->next;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
        }
    }
}

void delete()
{
    struct node* ptr;
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
    }

}

void display()
{
    struct node *ptr;
    ptr=front;
    if(front==NULL)
        prinf("Queue is Empty, Nothing to display\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
