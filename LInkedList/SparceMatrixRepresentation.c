
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};
struct node *first=NULL, *last, *curr;
//first = NULL;
void main()
{
    int m, n, i, j,item,ch=0,a=0;

    while(ch!=3)
    {
        printf("\n\n Chose one from the below options...\n");
        printf("\n 1:Create");
        printf("\n 2:Display");
        printf("\n 3:Exit");
        printf("\n Enter your choice: ");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // create
            printf("Enter the number of rows: ");
            scanf("%d", &m);
            printf("Enter the number of columns: ");
            scanf("%d", &n);
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("\nEnter value for A[%d][%d]: ", i, j);
                    scanf("%d", &item);
                    if(item != 0)
                    {
                        curr = (struct node *)malloc(sizeof(struct node));
                        curr->row = i;
                        curr->col = j;
                        curr->val = item;
                        curr->next = NULL;
                        if (first == NULL)
                        {
                            first = last = curr;
                        }
                        else
                        {
                            last->next = curr;
                            last = curr;
                        }
                    }
                }
            }
            break;
        case 2: // display the matrix
            if (first == NULL)
            {
                printf("Empty");
            }
            else
            {
                curr = first;
                for (i = 0; i < m; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        //if(curr->val!=0)
                        if (i==curr->row && j== curr->col)
                        {
                            printf("%d\t", curr->val);
                            curr = curr->next;
                            //printf("0\t");

                        }
                        else
                        {
                            printf("0    ");

                            //printf("%d\t", curr->val);
                            //curr = curr->next;
                        }
                    }
                    printf("\n");
                }
                curr=first;
                while(curr->next!=NULL)
                {
                    free(curr);
                    curr=curr->next;
                }
            }
            break;
        case 3:
            // exit(1);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
