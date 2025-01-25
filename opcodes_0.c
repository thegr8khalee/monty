#include "monty.h"

void push(stack_t **head, int line_number, char *arg)
{
    stack_t *newNode, *temp;
    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (is_int(arg) != 1)
    {
        fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    newNode->n = atoi(arg);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode; // First node in the list
    }
    else if (mode == 0) // Stack (LIFO) mode
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else if (mode == 1) // Queue (FIFO) mode
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void pall(stack_t **head)
{
    stack_t *temp = *head;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

void pint(stack_t **head, int line_number)
{
    stack_t *temp = *head;
    if (temp == NULL)
    {
        fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", temp->n);
}

void pop(stack_t **head, int line_number)
{
    stack_t *temp = *head;
    if (temp == NULL)
    {
        fprintf(stderr, "L<%d>: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }
    *head = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = NULL;
    }
    free(temp);
}

void swap(stack_t **head, int line_number)
{
    stack_t *first, *second;
    first = *head;
    second = first->next;

    if (!second)
    {
        fprintf(stderr, "L<%d>: can't swap, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    if (second->next == NULL)
    {
        first->next = NULL;
        first->prev = second;
        second->next = first;
        second->prev = NULL;
        *head = second;
    }
    else
    {
        first->next = second->next;
        first->prev = second;
        second->next = first;
        second->prev = NULL;
        *head = second;
    }
}
