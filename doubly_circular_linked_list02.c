#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newNode, *tail;

struct node *createNode()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = newNode->prev = NULL;
}

void insertAtBegin()
{
    newNode = createNode();
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

void insertAtEnd()
{
    newNode = createNode();
    if (tail == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }
    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
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
