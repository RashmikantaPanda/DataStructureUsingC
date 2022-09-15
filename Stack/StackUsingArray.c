//Using integer input as stack elements


#include<stdio.h>
#define MAX 20
void main()
{
    int top,i;
    int s[MAX];
    int ch;
    do
    {
        printf("\n1.Create Stack\n");
        printf("2.IsEmpty Stack\n");
        printf("3.PUSH\n");
        printf("4.POP\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter Your Choice : \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            top=-1;
            printf("Stack created successfully ");
            break;
        case 2:
            if(top==-1)
                printf("Ture . Stack is empty.");
            else
                printf("False . Stack is not empty.");
            break;
        case 3:
            if(top==MAX-1)
                printf("Stack is FULL ");
            else
                {
                    top=top+1;
                    printf("Enter item to push :\n");
                    scanf("%d",&s[top]);
                    printf("One item PUSHED Successfully ");
                }
            break;
        case 4:
            if(top==-1)
                printf("Empty Underflow ");
            else
            {
              printf("Poped item is : %d",s[top]);
              top=top-1;


            }
            break;
        case 5 :
            if(top==-1)
                printf("Stack is empty");
            else
            {
                printf("Stack contains  :");
                for(i=top; i>-1; i--)
                {
                    printf("\n%d",s[i]);
                }
            }
             break;

        case 6:
            exit(0);


        default:
            printf("Wrong Choice");
            break;

        }
    }while(ch!=6);

}

