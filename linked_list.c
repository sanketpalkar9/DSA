#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode;

int main()
{

    head = 0;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    printf("%d ", newnode->data);
    head = newnode;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        head->next = newnode;
    }

    return 0;
}
