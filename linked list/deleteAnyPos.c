#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // creating the structure node
    int data;
    struct node *next;
} node; // everytiime  we don't need to call the full function only node will work

// declaration of function node
void display(node **);
void ins_first(node **);
void del_poswise(node **);
void del_valwise(node **);
node *create();

int main()
{
    int ch; // choice
    node *head = NULL;
    do
    {
        printf("\n1. insert at first\n2. delete at position wise\n3. delete at value wise\n4. display\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            ins_first(&head); // sending the first node address
            break;
        case 2:
            /* code */
            del_poswise(&head); // sending the first node address
            break;

        case 3:
            /* code */
            del_valwise(&head); // sending the first node address
            break;

        case 4:
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
    node *new_node;                          // creating new node value
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
void del_poswise(node **head)
{
    int pos;
    printf("enter the position to delete\n");
    scanf("%d", &pos);
    if (*head == NULL)
    {
        // deleting the node but if its already empty then add first
        printf("insert_first");
    }
    else if((*head)->next == NULL){
        (*head)=(*head)->next;
    }
    else if( pos==1){
        (*head)=(*head)->next;
    }

    else
    {
        node *temp; // creating temporary variable to store value of head// works as a pointer
        temp = *head;

        for (int i = 2; i < pos; i++)
        {
            temp=temp->next;
        }
        
        temp->next = temp->next->next;


        // if (pos <= 0)
        // {
        //     node *temp2; // creating temporary variable to store value of head// works as a pointer
        //     temp2 = *head;
        //     temp2 = temp2->next;
        //     *head = temp2;
        // }
        // pos = pos - 1; //
        // while (pos != 0)
        // {
        //     temp = temp->next;
        //     pos = pos - 1;
        // }
        // temp->next = temp->next->next; // shifting the position of head
    }
}


void del_valwise(node **head){
    int pos;
    printf("enter the value which u want to delete\n");
    scanf("%d",&pos);
    if (*head== NULL)
    {
        printf("the value is NULL\n");
    }
    else if ((*head)->data==pos)
    {
        (*head)=(*head)->next;
    }
    else
    {
        node *tail;
        tail=*head;
        while (tail->next->data!=pos)
        {
            tail=tail->next;
        }
        tail->next = tail->next->next;
    }
    
}

void display(node **head)
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