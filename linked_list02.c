#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

void createNewNode()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0)
    {
        temp = head = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = temp->next;
    }
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

    createNewNode();
    createNewNode();
    createNewNode();
    printLinkedList();
    return 0;
}
