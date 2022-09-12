#include<stdio.h>

void push(int a[],int *top,int data);
int pop(int a[],int *top);
int peek(int a[],int *top);
void display(int a[],int *top);
int n=5;

void main(){
    
    int a[n];
    int top=-1;
    push(a,&top,1);
    push(a,&top,2);
    push(a,&top,3);
    push(a,&top,4);
    printf("%d\n",peek(a,&top));
    printf("%d\n",pop(a,&top));
    printf("%d\n",peek(a,&top));
    display(a,&top);
}

void push(int a[],int *top,int data){
    if(*top==n-1){
        printf("overflow");
        return;
    }
    *top=*top+1;
    a[*top]=data;
}

int peek(int a[],int *top){
    if(*top==-1){
        printf("underflow");
        return -1;
    }
    return a[*top];
}

int pop(int a[],int *top){
    if(*top==-1){
        printf("underflow");
        return -1;
    }
    int del=a[*top];
    *top=*top-1;
    return del;
}
void display(int a[],int *top){
    for (int i = 0; i <= *top; i++) {
        printf("%d\n",a[i]);
    }
}