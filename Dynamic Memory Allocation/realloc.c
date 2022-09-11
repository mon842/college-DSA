#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr,x;
    printf("Enter the size of elements: ");
    scanf("%d",&x);    
    ptr = (int*)calloc(x,sizeof(int));
    for (int i = 0; i < x; i++)
    {
        printf("enter value of %d ", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < x; i++)
    {
        printf("value of %d is %d ", i, ptr[i]);
    }

    printf("Enter the new size of elements: ");
    scanf("%d",&x);    
    ptr = (int*)realloc(ptr,x*sizeof(int));
    for (int i = 0; i < x; i++)
    {
        printf("enter value of %d ", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < x; i++)
    {
        printf("value of %d is %d ", i, ptr[i]);
    }
    free(ptr);
    return 0;
}