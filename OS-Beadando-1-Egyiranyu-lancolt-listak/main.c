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

void printList (node *node) {
    if (node == NULL) printf("Empty list.");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n\n");
}

void insert (node **head, node *previous_node, data data) {
    printf("Inserting value %d between %d and %d:\n", data, previous_node->data, previous_node->next->data );
    if (previous_node == NULL) {
        printf("Previous node was NULL!");
    }

    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;

    printList(*head);
}

void append (node **head, data data) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        printf("Appending value %d as first item: \n", data);
        *head = new_node;
        printList(*head);
        return;
    }

    node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;

    printf("Appending value %d after item %d: \n", data, last->data);

    printList(*head);
}

void deleteDataFirstOccurence (node **head, data data) {
    printf("Deleting first occurence of %d. \n", data);
    node *current = *head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }
    printList(*head);
}


int main()
{
    node *head = NULL;
    printList(head);

    append(&head,2);
    append(&head,8);
    insert(&head, head, 4);

    deleteDataFirstOccurence(&head, 4);
    printList(head);

    free(head);

    return 0;
}
