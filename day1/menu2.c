#include <stdlib.h>
#include <stdio.h>

void delete (int a[],int *len);
void insert(int a[],int *len);
void print1(int a[],int *len);

int main()
{
    int *a,x;
    printf("Enter the size of elements: ");
    scanf("%d",&x);    
    a = (int*)calloc(x,sizeof(int));// creating an array of length x
    for (int i = 0; i < x; i++)
    {
        printf("enter value of %d ", i);
        scanf("%d", &a[i]);
    }

    int  ch;
    int *len = sizeof(a) / sizeof(int);
    do
    {
        printf("1 to delete pos\n");
        printf("2 to insert pos\n");
        printf("3 to print \n");
        printf("4 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
            {
                delete(a,&x);
                break;
            }

            case 2:
            {
                insert(a,&x);
                break;
            }

            case 3:
            {
                print1(a,&x);
                break;
            }

            case 4:
                exit(0);
        }
    }
    while (1);
    return 0;
}

void delete(int a[],int *len)
{
    int pos;
    printf("Enter the number of pos: ");
    scanf("%d", &pos);
    for (int i = pos; i < *len - 1; i++)
    {
        a[i] = a[i + 1]; // 
    }
    *len=*len-1;
    a = (int*)realloc(a,(*len)*sizeof(int));
    
}

void insert(int a[],int *len)
{
    int pos, val;
    printf("Enter the number of pos: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);
    *len = *len + 1;
    a = (int*)realloc(a,(*len)*sizeof(int));
    for (int i = *len; i >= pos; i--)
    {
        if (i == pos)
        {
            a[i] = val;
        }
        else
            a[i] = a[i - 1];
    }
}
void print1(int a[],int *len)
{
    printf("\n");
    for (int i = 0; i < *len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}