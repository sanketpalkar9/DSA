#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

void insertAtBegin()
{

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertAtPos()
{
    int pos;
    printf("Enter the location you want to insert your data:");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    temp = head;
    for (int i = 1; i < pos - 1 && temp != 0; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position");
        return;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) // If the list is empty
    {
        temp = head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void printLinkedList()
{
    struct node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{

    head = 0;
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtPos();
    insertAtBegin();

    printLinkedList();
    return 0;
}
