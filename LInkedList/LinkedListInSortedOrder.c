#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node *next;
};
struct node *first,*last,*curr,*p,*q;
int main()
{
    int ch=1;
    first=last=NULL;
    while(ch!=0)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        curr->next=NULL;
        printf("Enter the item : ");
        scanf("%d",&curr->info);
        if(first==NULL)
            first=last=curr;
        else
        {
            if(curr->info < first->info)
            {
                curr->next=first;
                first=curr;
            }
            else
            {
                p=first;
                q=p->next;
                while((q->info < curr->info) && q!=NULL)
                {
                    p=q;
                    q=p->next;
                }
                p->next=curr;
                curr->next=q;
            }
        }
        printf("Do you want to insert more ? (1/0) ");
        scanf("%d", &ch);
   }
    printf("The List is : \n");
    curr=first;
    while(curr!=NULL)
    {
        printf("%d  ",curr->info);
        curr=curr->next;

    }

    return 0;
}
