#include <stdio.h>
#include <stdlib.h>
int a[20];
int n, val, i,j,r,pos,temp;
void create();
void display();
void insert();
void Delete();
void sort();
void Search();
int main()
{
    int choice = 1;
    while (choice)
    {
        printf("\n\n——–MENU———–\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.SORTING\n");
        printf("6.SEARCHING\n");
        printf("7.EXIT\n");
        printf("———————–");
        printf("\nENTER YOUR CHOICE:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            Delete();
            break;
        case 5:
            sort();
            break;
        case 6:
            Search();
            break;
        case 7:
            exit(0);
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    }
    return 0;
}
//creating an array
void create()
{
    printf("\nEnter the size of the array elements:\t");
    scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
//displaying an array elements
void display()
{
   // int i;
   if(n==0)
        printf("Empty Array !");
   else
        printf("\nThe array elements are:\n");
        for (i = 0; i < n; i++)
        {
            printf("%d\t", a[i]);
        }
}
//inserting an element into an array
void insert()
{
    printf("\nEnter the position for the new element:\t");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d", &val);
    for (i = n-1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
}
//deleting an array element
void Delete()
{
    printf("\nEnter the position of the element to be deleted:\t");
    scanf("%d", &pos);
    val = a[pos];
    for (i = pos; i < n -1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n-1;
    printf("\nThe deleted element is =%d", val);
}
void sort()
{

 for (i = 0; i<n; ++i)
 {
    for (j=i+1; j<n; ++j)
    {
         if (a[i] > a[j])
            {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
    }
  }
}

void Search()
{
    printf("Enter the item to be searched: ");
   scanf("%d", &r);

   i = 0;
   while (i<n && r!= a[i])
    {
      i++;
   }

   if (r==a[i])
   {
      printf("The element is found in the position = %d", i + 1);
   }
   else
   {
      printf("Element not found!");
   }
}


