#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newNode, *tail;

void creation()
{

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = newNode->prev = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        tail = newNode;
    }
}

void printList()
{
    struct node *temp = head;
    do
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("NULL");
}

int main(int argc, char const *argv[])
{
    head = NULL;
    creation();
    creation();
    creation();
    creation();
    printList();
    return 0;
}
