#include<stdio.h>
#include<stdlib.h>

typedef struct node {// creating the structure node
    int data;
    struct node *next;
    struct node *prev;
}node; // everytiime  we don't need to call the full function only node will work


// declaration of function node
void display(node **);
void ins_first(node **);
node *create();

int main()
{
    int ch;// choice
    node *head = NULL;
    do
    {
        printf("\n1. insert at first\n2. display\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            ins_first(&head);// sending the first node address
            break;
        case 2:
            /* code */
            display(&head);// sending the first node address
            break;
        
        default:
            exit(0);
        }
    } while (1);
    
    return 0;
}

node *create(){
    node *new_node;// creating new node value
    new_node = (node *)malloc(sizeof(node));// allocating its size
    printf("enter new node\n");
    scanf("%d", &new_node->data);// node's data
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void ins_first(node **head){
    node *temp;// creating temporary variable  and initializing its value to the new value
    temp=create();
    if(*head==NULL){
        *head = temp;
    }
    else{
        (*head)->prev = temp;
        temp->next=(*head);//attaching the node at the first of head
        *head=temp;// shifting the position of head
    }
}

void display(node **head){
    node *temp;// creating temporary variable to store value of head// works as a pointer
    temp=*head;
    while(temp!=NULL){// if not null print its value and go to the next
        printf("%d-> ", temp->data);
        temp=temp->next;
    }
    printf("end");
    printf("\n");
}