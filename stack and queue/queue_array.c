#include<stdio.h>


void add(int arr[], int i, int *rear);

int peek(int arr[], int *rear);
int pop(int arr[], int *rear);
int n=10;

void main()
{
    int arr[n];
    int rear=-1;
    add(arr, 0, &rear);
    add(arr, 1, &rear);
    add(arr, 2, &rear);
    add(arr, 4, &rear);
    printf("%d\n", peek(arr, &rear));
    printf("%d\n", pop(arr, &rear));
    printf("%d\n", pop(arr, &rear));

}

void add(int arr[], int i, int *rear){
    if(*rear==n-1){
        printf("overflow\n");
        return;
    }
    *rear = *rear + 1;
    arr[*rear]=i;
}

int peek(int arr[], int *rear){
    if (*rear==-1)
    {
        printf("underflow");
        return -1;
    }
    return arr[0];   
}

int pop(int arr[], int *rear){
    if (*rear==-1)
    {
        printf("underflow\n");
        return -1;
    }
    int front=arr[0];
    for (int i = 0; i < *rear; i++)
    {
        arr[i]=arr[i+1];
    }
    *rear=*rear-1;
    return front; 
}