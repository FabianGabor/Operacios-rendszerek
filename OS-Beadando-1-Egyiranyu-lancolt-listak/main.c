/*
 * Készítsen C++ vagy C# „console” alkalmazást, amely szöveges állományból beolvas 10 darab számot 0,1,2,…,9 és összefűzi azokat egyirányú láncba.
 * A program képes legyen beszúrni új elemeket, illetve törölni létezőket. Minden művelet végrehajtása után a teljes módosított lista legyen megjelenítve.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int data;

typedef struct node {
    data data;
    struct node *next;
} node;

void insert (node *previous_node, data data) {
    if (previous_node == NULL) {
        printf("Previous node was NULL!");
    }

    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;
}

void append (node **head, data data) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(node *node) {
    if (node == NULL) printf("Empty list.");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main()
{
    node *head = NULL;
    printList(head);

    append(&head,8);
    printList(head);

    return 0;
}
