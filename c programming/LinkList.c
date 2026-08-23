#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int length(struct Node *head)
{
    int count=0;

    while(head != NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

int main()
{
    struct Node *head = NULL, *current = NULL;
    
    for(int i = 1; i <= 5; i++) {
        if(head == NULL) {
            head = current = createNode(i);
        } else {
            current->next = createNode(i);
            current = current->next;
        }
    }
    
    Traversal(head);
    return 0;
}