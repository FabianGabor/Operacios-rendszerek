/*
 * Készítsen C++ vagy C# „console” alkalmazást, amely szöveges állományból beolvas 10 darab számot 0,1,2,…,9 és összefűzi azokat egyirányú láncba.
 * A program képes legyen beszúrni új elemeket, illetve törölni létezőket. Minden művelet végrehajtása után a teljes módosított lista legyen megjelenítve.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
//#include <limits.h>

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
    node *tmp;

    // check if data to be deteled is the head
    if (current->data == data) {
        tmp = current->next;
        free(current);
        *head = tmp;
        printList(*head);
        return;
    }

    // check if data to be deteled is in the list
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            printList(*head);
            return;
        }
        else
            current = current->next;
    }
}

void deleteDataAlltOccurences (node **head, data data) {
    printf("Deleting all occurences of %d. \n", data);

    node *current = *head;
    node *tmp;

    // check if data to be deteled is the head
    if (current->data == data) {
        tmp = current;
        free(head);
        *head = tmp->next;
        free(tmp);
    }

    while (current->next != NULL) {
        if (current->next->data == data) {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
            current = current->next;
    }
    printList(*head);
}

void deleteDataAtPosition (node **head, unsigned int position) {
    node *current = *head;

    for (unsigned int i=1; i<position-1; i++) {
        current = current->next;
    }

    printf("Deleting data %d at position %d: \n", current->next->data, position);

    node *tmp = current->next;
    current->next = tmp->next;
    free(tmp);

    printList(*head);
}

void destroyList(node **head) {
    node *current = *head;
    node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printList(*head);
}


void parseStr (node **head, char str[255], char delim[])
{
    //char delim[] = " ";
    char *ptr = strtok(str, delim);

    while(ptr != NULL)
    {
        append(head, atoi(ptr) );
        ptr = strtok(NULL, delim);
    }
}


void readFromFile(node **head, char filename[255], char delim[]) {
    FILE *file;
    char str[255];

    file = fopen(filename, "r");
    fgets(str, 255, file);

    parseStr(head, str, delim);

    fclose(file);
}

int main()
{
    node *head = NULL;
    printList(head);

    /*
    append(&head,2);
    append(&head,8);
    insert(&head, head, 4);
    append(&head,2);
    append(&head,2);
    append(&head,5);

    deleteDataFirstOccurence(&head, 2);
    deleteDataAlltOccurences(&head, 2);
    deleteDataAtPosition(&head, 3);

    destroyList(&head);
    */
    readFromFile(&head, "input", ","); // head of list, name of file to read from, numbers delimiter character (default space)

    printf("List read from file: \n");
    printList(head);

    return 0;
}
