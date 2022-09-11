#include <stdio.h>
#include<stdlib.h>


typedef struct node
{ // creating the structure node
    int data;
    struct node *next;
} node; // everytiime  we don't need to call the full function only node will work


node *create();
void display(node **);
void display(node **);
void ins_first(node **);
void ins_last(node **);
void ins_poswise(node **);
void ins_valwise(node **);


int main(){
    int ch;
    node *head=NULL;
    do
    {
        printf("\n1. insert at first\n2. insert  at last\n3. insert in any positionWise\n4. insert in any valueWise\n5. display\n6. exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:{
            ins_first(&head);
            break;
        }
        case 2:{
            ins_last(&head);
            break;
        }
        case 3:{
            ins_poswise(&head);
            break;
        }   
        case 4:{
            ins_valwise(&head);
            break;
        } 
        case 5:
            /* code */
            display(&head); // sending the first node address
            break;
        
        default:
            exit(0);
        }
    } while (1);
    return 0;
}

node *create()
{
    node *new_node;  // creating new node value
    new_node = (node *)malloc(sizeof(node)); // allocating its size
    printf("enter new node\n");
    scanf("%d", &new_node->data); // node's data
    new_node->next = NULL;
    return new_node;
}

void ins_first(node **head)
{
    node *temp; // creating temporary variable  and initializing its value to the new value
    temp = create();
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = (*head); // attaching the node at the first of head
        *head = temp;         // shifting the position of head
    }
}

void ins_last(node **head)
{
    node *temp; // creating temporary variable  and initializing its value to the new value
    temp = create();
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;
        while (tail->next != NULL)
        { // if not null print its value and go to the next
            tail = tail->next;
        }
        tail->next = temp;
        tail= temp;
    }
}

void ins_poswise(node **head)
{
    int pos;
    printf("enter the position to insert\n");
    scanf("%d", &pos);
    node *temp;
    temp=create();
    if (*head == NULL)
    {
        printf("insert_first");
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;

        // pos = pos - 1; //
        while (pos != 0)
        {
            tail = tail->next;
            pos = pos - 1;
        }
        node *tailN;
        tailN=tail->next;
        tail->next=temp;
        temp->next =tailN;
    }
}

void ins_valwise(node **head){
    int pos;
    printf("enter the value where u want to insert the value\n");
    scanf("%d",&pos);
    node *temp;
    temp=create();
    if (*head== NULL)
    {
        *head = temp;
    }
    else
    {
        node *tail;
        tail=*head;
        while (tail->data!=pos)
        {
            tail=tail->next;
        }
        node *tailN;
        tailN=tail->next;
        tail->next=temp;
        temp->next =tailN;
    }
    
}


void display(node **head)
{
    if (*head == NULL)
    {
        printf("insert first node list is empty\n");
    }
    else
    {
        node *temp; // creating temporary variable to store value of head// works as a pointer
        temp = *head;
        while (temp != NULL)
        { // if not null print its value and go to the next
            printf("%d-> ", temp->data);
            temp = temp->next;
        }
        printf("end");
        printf("\n");
    }
    
}