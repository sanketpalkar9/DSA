#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *newnode;

void deleteFromBegin()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

void deleteFromPos()
{
    int pos;
    printf("Enter the postion you want to delete: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        deleteFromBegin();
    }

    struct node *temp;
    int i = 0;
    while (i < pos && temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void deleteFromEnd()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

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
    deleteFromBegin();
    deleteFromBegin();
    deleteFromEnd();
    printLinkedList();

    return 0;
}
