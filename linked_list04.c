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
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
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
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delFromBegin()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void delFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *prev = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delFromPos()
{
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        delFromBegin();
        return;
    }

    struct node *prev = NULL;
    temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    head = NULL;

    createNewNode();
    createNewNode();
    createNewNode();
    createNewNode();
    createNewNode();

    delFromPos();
    delFromBegin();
    delFromEnd();

    printLinkedList();

    return 0;
}
