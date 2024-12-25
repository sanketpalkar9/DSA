#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

struct node *createNode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void insertAtBegin()
{
    struct node *newnode = createNode();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtPos()
{
    int pos, i = 1;
    struct node *newnode = createNode();
    struct node *temp;
    printf("Enter the position you want to insert data: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid Position :( ");
    }
    else if (pos == 1)
    {
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    else
    {
        temp = head;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            printf("Position out of bounds\n");
        }
        else
        {
            newnode->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

void insertAtEnd()
{
    struct node *newnode = createNode();
    struct node *temp;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void printLinkedList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    head = NULL;

    insertAtEnd();
    insertAtEnd();
    insertAtEnd();
    insertAtPos();
    insertAtBegin();
    insertAtBegin();
    printLinkedList();

    return 0;
}