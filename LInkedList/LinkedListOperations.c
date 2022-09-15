//Menu Driven Program for linkedList
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;

void display()
{
    struct node* ptr;

    if(head==NULL)
        printf("\n\nList is Empty\n");
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf(" ->\t%d",ptr->data);
            ptr=ptr->next;

        }
    }
}

void insertBeg()
{
    int data;
    struct node* ptr;
    ptr=malloc(sizeof(struct node));
    printf("Enter the number to be inserted :\n");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    head=ptr;
}

void insertEnd()
{
    int data;
     struct node *ptr, *temp;
    ptr=malloc(sizeof(struct node));
     printf("Enter the number to be inserted :\n");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=NULL;
    temp=head;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }

      temp->next=ptr;
    }
}
void insertAny()
{
    struct node *ptr,*temp;
    int pos,data,i=1;
    ptr=malloc(sizeof(struct node));
    printf("Enter the POSITION and DATA to be inserted :\n");
    scanf("%d %d",&pos,&data);
    temp=head;
    if(pos==1||pos==0)
    {
        ptr->data=data;
        ptr->next=temp;
        head=ptr;

    }
   else
   {
       while(i<pos-1)
        {
          temp=temp->next;
          i++;
        }
        ptr->next=temp->next;
        ptr->data=data;
        temp->next=ptr;
   }
}
void deleteBeg()
{
    struct node* temp;
    if (head==NULL)
        printf("Empty List");
    else
    {
      temp=head;
      head=temp->next;
      temp->next=NULL;
      free(temp);
    }
}
void deleteEnd()
{
    struct node *temp,*prev_node;
    temp=head;
    if(temp==NULL)
        printf("LIST IS EMPTY ");
    else{
        while(temp->next!=NULL)
        {
            prev_node=temp;
            temp=temp->next;
        }
        free(temp);
        prev_node->next=NULL;

    }
}
void deleteAny()
{
    struct node *currentNode,*nextNode;
    int index;
    printf("Enter the index you want to delete the element : ");
    scanf("%d",&index);
    currentNode=head;
    nextNode=currentNode->next;
    int i=0;
    while(i!=index-1)
    {
        currentNode=currentNode->next;
        nextNode=nextNode->next;
        i++;
    }
    currentNode->next=nextNode->next;
    free(nextNode);
    printf("Node deleted at index %d ",index);

}
void sort()
{
    int temp;
    struct node* current=head;
    struct node* currentNext=NULL;
    if(current==NULL)
        printf("List is empty");
    else{
        while(current!=NULL)
        {
            currentNext=current->next;
            while(currentNext!=NULL)
            {
                if(current->data > currentNext->data)
                {
                    temp=current->data;
                    current->data=currentNext->data;
                    currentNext->data=temp;
                }
                currentNext=currentNext->next;
            }
            current=current->next;

        }
    }
}

void ReverseList()
{
    struct node* current=head;
    struct node *prev=NULL, *next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("List is Reverted now.");
}
/*void CreateInSortedOrder()
{
    int data;
    struct node *ptr,*curr, *prev;;
    ptr=(struct node*)malloc(sizeof(struct node));
    //temp=head;
    printf("Enter the node to be inserted :");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
         curr=head;
         prev=curr;
         while(curr->data <= data)
         {
             prev=curr;
             curr=curr->next;
         }
         if(curr==NULL)
            prev->next=ptr;
         else{
            ptr->next=prev->next;
            prev->next=ptr;
         }
    }
} */
void countNode()
{
    int i=0;
    struct node *temp;
    temp=head;
   // if (temp==Null)
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    printf("No of node is : %d",i);
}

void displayIthElement()
{
      int i,j=1;
    struct node *temp;
    temp=head;
    printf("Enter the position of the node you want to display : ");
    scanf("%d",&i);
    while(j!=i && temp!=NULL)
    {
        temp=temp->next;
        j++;
    }
    if(temp==NULL)
        printf("No node available.");
    else
        printf("Content of %d th node is : %d",j,temp->data);

}

void splitList()
{
    int data;
    struct node *temp,*temp1,*ptr;
    temp=head;

    if(temp==NULL)
        printf("Empty list");
    else
   {

     printf("Enter the data of the node, from where to split : ");
     scanf("%d",&data);
     ptr=temp;
    while(temp!=NULL)
     {
        if(temp->data==data)
            break;
        temp=temp->next;
     }
     if(temp==NULL)
        printf("Value does not exist.");
     else
     {
       temp1=temp->next;
       temp->next=NULL;
     }

     printf("\nList 1 : ");
     while(ptr!=NULL)
     {
         printf("-> %d ",ptr->data);
         ptr=ptr->next;

     }
     printf("\nList 2 :  ");
      while(temp1!=NULL)
     {
         printf("-> %d ",temp1->data);
         temp1=temp1->next;

     }
   }
}
 void main()
 {

  int choice;
  while(1)
  {
     printf("\n\n 1. To see List");
     printf("\n\n 2. To Insert at begining");
     printf("\n\n 3. To Insert at the  End");
     printf("\n\n 4. To Insert at Any Position");
     printf("\n\n 5. To delete from begining");
     printf("\n\n 6. To delete from the End");
     printf("\n\n 7. To delete from any position");
     printf("\n\n 8. To Sort a List");
     printf("\n\n 9. To Reverse a List");
     //printf("\n\n 10. Create a list in sorted order.");
     printf("\n\n 10. Count number of nodes.");
     printf("\n\n 11. Display the 'i'th Element.");
   //  b     printf("\n\n 12. To Split the List");
     printf("\n\n 13. To EXIT ");
     scanf("%d",&choice);

     switch(choice)
     {
     case 1:
         display();
         break;
     case 2:
        insertBeg();
        break;
     case 3:
        insertEnd();
        break;
     case 4:
        insertAny();
        break;
     case 5:
        deleteBeg();
        break;
     case 6:
        deleteEnd();
        break;
     case 7:
        deleteAny();
        break;
     case 8:
        sort();
        break;
     case 9:
        ReverseList();
        break;
    /*case 10:
        CreateInSortedOrder();
        break; */
    case 10:
        countNode();
        break;
    case 11:
        displayIthElement();
        break;
    case 12:
        splitList();
        break;

     case 13:
        exit(1);
        break;
     default:
        printf("Incorrect Choice\n");
     }
  }
 }

