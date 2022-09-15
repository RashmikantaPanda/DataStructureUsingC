#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int row;
    int col;
    struct node *next;

};

void createNewNode(struct node** head,int data,int row, int col)
{
    struct node *temp, *ptr;
    temp=*head;
    if(temp==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->row=row;
        temp->col=col;
        temp->next=NULL;
    }
    else
    {
        while(temp!=NULL)
            temp=temp->next;

        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->row=row;
        ptr->col=col;
        ptr->next=NULL;
        temp->next=ptr;

    }
}

void displayList(struct node* start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;

    printf("row_position: ");
    while(temp != NULL)
    {
        printf("%d",temp->row);
        temp = temp->next;
    }
    printf("\n");

    printf("column_postion: ");
    while(r != NULL)
    {
        printf("%d ", r->col);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while(s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}
}


int main()
{
   // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    /* Start with the empty list */
    struct Node* start = NULL;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)

            // Pass only those values which are non - zero
            if (sparseMatric[i][j] != 0)
                createNewNode(&start, sparseMatric[i][j], i, j);

    displayList(start);

    return 0;
}
