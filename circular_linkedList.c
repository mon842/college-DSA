#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ // creating the structure node
    int data;
    struct node *next;
} node; // everytiime  we don't need to call the full function only node will work

node *create();

void ins_first(node **);
void ins_last(node **);

void del_last(node **);
void del_first(node **);

void ins_poswise(node **);
void ins_valwise(node **);

void del_poswise(node **);
void del_valwise(node **);

void display(node **);

int main()
{
    int ch;
    node *head = NULL;
    do
    {
        printf("\n1. insert at first\n2. insert  at last\n3. delete first\n4. delete last\n5. insert in any positionWise\n6. insert in any valueWise5.\n7. delete in any positionWise\n8. delete in any valueWise\n9. display\n10. exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            ins_first(&head);
            break;
        }
        case 2:
        {
            ins_last(&head);
            break;
        }
        case 3:
        {
            del_first(&head);
            break;
        }
        case 4:
        {
            del_last(&head);
            break;
        }
        case 5:
        {
            ins_poswise(&head);
            break;
        }
        case 6:
        {
            ins_valwise(&head);
            break;
        }
        case 7:
        {
            del_poswise(&head);
            break;
        }
        case 8:
        {
            del_valwise(&head);
            break;
        }
        case 9:
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
    else if ((*head)->next == NULL)
    {
        (*head)->next = temp;
        temp->next = (*head);
        *head = temp;
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;
        do
        {
            tail = tail->next;
        } while (tail->next != (*head));

        tail->next = temp;
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
    else if ((*head)->next == NULL)
    {
        (*head)->next = temp;
        temp->next = (*head);
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;

        do
        {
            tail = tail->next;
        } while (tail->next != (*head));

        tail->next = temp;
        temp->next = (*head);
        tail = temp;
    }
}

void del_first(node **head)
{
    if (*head == NULL)
    {
        // ins_first(&head); // deleting the node but if its already empty then add first
        printf("insert_first list is empty");
    }
    else if ((*head)->next == NULL)
    {
        (*head) = NULL;
    }
    else if ((*head)->next->next == (*head))
    {
        node *temp;
        temp = (*head)->next;
        (temp)->next = NULL;
        *head = temp;
    }
    else
    {
        node *temp; // creating temporary variable to store value of head// works as a pointer
        temp = (*head)->next;
        node *tail;
        tail = (*head);

        do
        {
            tail = tail->next;
        } while (tail->next != (*head));

        tail->next = temp;
        *head = temp; // shifting the position of head
    }
}

void del_last(node **head)
{
    if (*head == NULL)
    {
        printf("insert first node empty");
    }
    else if ((*head)->next == NULL)
    {
        (*head) = NULL;
    }
    else if ((*head)->next->next == (*head))
    {
        (*head)->next = NULL;
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;
        node *pretail;
        pretail = *head;

        while (tail->next != (*head))
        { // if not null print its value and go to the next
            pretail = tail;
            tail = tail->next;
        }
        pretail->next = (*head);
    }
}

void ins_poswise(node **head)
{
    int pos;
    printf("enter the position to insert\n");
    scanf("%d", &pos);
    node *temp;
    temp = create();
    if (*head == NULL)
    {
        printf("insert at first\n");
        *head = temp;
    }
    else
    {
        node *tail; // creating temporary variable to store value of head// works as a pointer
        tail = *head;

        // pos = pos - 1; //
        while (pos != 1)
        {
            tail = tail->next;
            pos = pos - 1;
        }
        node *tailN;
        tailN = tail->next;

        tail->next = temp;
        temp->next = tailN;
    }
}

void ins_valwise(node **head)
{
    int pos;
    printf("enter the value where u want to insert the value\n");
    scanf("%d", &pos);
    node *temp;
    temp = create();
    if (*head == NULL)
    {
        *head = temp;
    }
    else if ( (*head)->next == NULL)
    {
        (*head)->next = temp;
        temp->next = (*head);
    }
    else
    {
        node *tail;
        tail = *head;
        while (tail->data != pos)
        {
            tail = tail->next;
        }
        node *tailN;
        tailN = tail->next;
        tail->next = temp;
        temp->next = tailN;
    }
}

void del_valwise(node **head)
{
    int pos;
    printf("enter the value which u want to delete\n");
    scanf("%d", &pos);
    if (*head == NULL)
    {
        printf("the value is NULL\n");
    }
    else if ((*head)->data == pos)
    {
        if (*head == NULL)
        {
            // ins_first(&head); // deleting the node but if its already empty then add first
            printf("insert_first list is empty");
        }
        else if ((*head)->next == NULL)
        {
            (*head) = NULL;
        }
        else if ((*head)->next->next == (*head))
        {
            node *temp;
            temp = (*head)->next;
            (temp)->next = NULL;
            *head = temp;
        }
        else
        {
            node *temp; // creating temporary variable to store value of head// works as a pointer
            temp = (*head)->next;
            node *tail;
            tail = (*head);

            do
            {
                tail = tail->next;
            } while (tail->next != (*head));

            tail->next = temp;
            *head = temp; // shifting the position of head
        }
    }
    else if (pos == 1)
    {
        (*head) = (*head)->next;
    }

    else
    {
        node *tail;
        tail = *head;
        while (tail->next->data!=pos)
        {
            tail=tail->next;
        }
        // while (tail->data != pos)
        // {
        //     tail = tail->next;
        // }
        tail->next = tail->next->next;
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
    else if (pos == 1)
    {
        if (*head == NULL)
        {
            // ins_first(&head); // deleting the node but if its already empty then add first
            printf("insert_first list is empty");
        }
        else if ((*head)->next == NULL)
        {
            (*head) = NULL;
        }
        else if ((*head)->next->next == (*head))
        {
            node *temp;
            temp = (*head)->next;
            (temp)->next = NULL;
            *head = temp;
        }
        else
        {
            node *temp; // creating temporary variable to store value of head// works as a pointer
            temp = (*head)->next;
            node *tail;
            tail = (*head);

            do
            {
                tail = tail->next;
            } while (tail->next != (*head));

            tail->next = temp;
            *head = temp; // shifting the position of head
        }
    }
    else if ((*head)->next == NULL)
    {
        (*head) = (*head)->next;
    }
    else if (pos == 1)
    {
        (*head) = (*head)->next;
    }

    else
    {
        node *temp; // creating temporary variable to store value of head// works as a pointer
        temp = *head;

        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }
}

void display(node **head)
{
    if (*head == NULL)
    {
        printf("insert first node list is empty\n");
    }
    else if ((*head)->next == NULL)
    {
        printf("%d->end \n", (*head)->data);
    }

    else
    {
        node *temp; // creating temporary variable to store value of head// works as a pointer
        temp = *head;
        do
        {
            printf("%d->", temp->data);
            temp = temp->next;
        } while (temp != (*head));

        printf("end");
        printf("\n");
    }
}
