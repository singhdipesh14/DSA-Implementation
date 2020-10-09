#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} * Node;

int isEmpty(Node first)
{
    if (first == NULL)
    {
        return 1;
    }
    return 0;
}

void insertF(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*first))
    {
        n->next = n;
        n->prev = n;
        *first = n;
        return;
    }
    if ((*first)->next == *first)
    {
        (*first)->next = n;
        n->next = *first;
        n->prev = *first;
        (*first)->prev = n;
        *first = n;
        return;
    }
    n->next = *first;
    Node last = (*first)->prev;
    (*first)->prev = n;
    last->next = n;
    n->prev = last;
    *first = n;
}

void insertR(Node *first, int key)
{
    Node n = (Node)malloc(sizeof(struct node));
    n->val = key;
    n->next = NULL;
    n->prev = NULL;
    if (isEmpty(*first))
    {
        n->next = n;
        n->prev = n;
        *first = n;
        return;
    }
    if ((*first)->next == *first)
    {
        (*first)->next = n;
        n->next = *first;
        n->prev = *first;
        (*first)->prev = n;
        return;
    }
    Node last = (*first)->prev;
    n->next = *first;
    n->prev = last;
    last->next = n;
    (*first)->prev = n;
}

void deleteF(Node *first)
{
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next = *first)
    {
        printf("\nThe deleted element is : %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node last = (*first)->prev;
    Node infrontof1 = (*first)->next;
    last->next = infrontof1;
    infrontof1->prev = last;
    printf("\nThe deleted element is : %d", (*first)->val);
    free(*first);
    *first = infrontof1;
}

void deleteR(Node* first){
    if (isEmpty(*first))
    {
        printf("\nThe list is empty, nothing to delete");
        return;
    }
    if ((*first)->next = *first)
    {
        printf("\nThe deleted element is : %d", (*first)->val);
        free(*first);
        *first = NULL;
        return;
    }
    Node last = (*first)->prev;
    Node prevoflast = last->prev;
    prevoflast->next = *first;
    (*first)->prev = prevoflast;
    printf("\nThe deleted element is : %d", last->val);
    free(last);
}

void display(Node first){
    if (isEmpty(first))
    {
        printf("\nThe list is empty, nothing to print");
        return;
    }
    printf("\n");
    Node cur = first;
    while(cur->next!=first){
        printf("%d\t", cur->val);
        cur = cur->next;
    }
    printf("%d", first->prev->val);
}

int main()
{
    Node first = NULL;
    int choice = 0, ele;
    while (choice < 7)
    {
        printf("\n1 : Display the list \n2 : Insert Front \n3 : Insert Rear \n4 : Remove front \n5 : Remove Rear \n6 : Check for empty or full \n7 : Exit");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        printf("\n#################");
        switch (choice)
        {
        case 1:
            display(first);
            break;

        case 2:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertF(&first, ele);
            break;

        case 3:
            printf("\nEnter the element to be inserted : ");
            scanf("%d", &ele);
            insertR(&first, ele);
            break;

        case 4:
            deleteF(&first);
            break;

        case 5:
            deleteR(&first);
            break;
        case 6:
            if (isEmpty(first))
            {
                printf("\nThe list is empty");
            }
            else
            {
                printf("\nThe list is NOT empty");
            }
            break;
        }
        printf("\n#################\n");
    }
    return 0;
}