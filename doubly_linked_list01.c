#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *newnode;

void createNode()
{

    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
}

void printLinkedList()
{
    struct node *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(int argc, char const *argv[])
{
    head = NULL;

    createNode();
    createNode();
    createNode();
    createNode();
    printLinkedList();

    return 0;
}
