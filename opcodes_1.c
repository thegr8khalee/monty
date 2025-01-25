#include "monty.h"

void mod(stack_t **head, int line_number){
    stack_t *first, *second;
    first = *head;
    int sum = 0;
    second = first->next;

    if(first->n == 0){
        fprintf(stderr, "L<%d>: division by zero", line_number);
        exit(EXIT_FAILURE);
    }
    if (!second)
    {
        fprintf(stderr, "L<%d>: can't mod, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    sum = second->n % first->n;

    pop(head, line_number);

    (*head)->n = sum;
}

void pchar(stack_t **head, int line_number){
    if(!head){
        fprintf(stderr, "L<%d>: can't pchar, stack empty", line_number);
        exit(EXIT_FAILURE);
    }
    if((*head)->n < 31 || (*head)->n > 127){
        fprintf(stderr, "L<%d>: can't pchar, value out of range", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", (*head)->n);
}

void pstr(stack_t **head, int line_number)
{
    stack_t *temp;

    if (head == NULL || *head == NULL) // Check if the stack is empty
    {
        fprintf(stderr, "L<%d>: can't pstr, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *head; // Assign the top of the stack to `temp`

    while (temp != NULL && temp->n > 31 && temp->n < 127) // Loop through printable ASCII
    {
        printf("%c", temp->n);
        temp = temp->next;
    }

    printf("\n"); // Print a newline after the string
}

void rotl(stack_t **head, int line_number){
    stack_t *first, *last;

    if (head == NULL || *head == NULL) // Check if the stack is empty
    {
        fprintf(stderr, "L<%d>: can't pstr, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    //newNode = malloc(sizeof(stack_t));

    // if(!newNode){
    //     fprintf(stderr, "Error: malloc failed\n");
    //     exit(EXIT_FAILURE);
    // }

    first = *head;
    last = *head;

    while(last->next != NULL){
        last = last->next;
    }

    *head = first->next;      // Update head to the second element
    (*head)->prev = NULL;     // Set the new head's prev to NULL

    last->next = first;       // Link the last node to the former head
    first->prev = last;       // Update the former head's prev to the last node
    first->next = NULL;  
}

void rotr(stack_t **head, int line_number)
{
    stack_t *last, *second_last;

    (void)line_number; // To avoid unused variable warning

    // Check if the stack is empty or has only one element
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    last = *head;

    // Traverse to the last node
    while (last->next != NULL)
        last = last->next;

    // Find the second-to-last node
    second_last = last->prev;

    // Update pointers for rotation
    second_last->next = NULL; // Disconnect the last node from the stack
    last->prev = NULL;        // Remove the backward link from the last node
    last->next = *head;       // Link the last node to the current head
    (*head)->prev = last;     // Update the current head's prev to the last node
    *head = last;             // Update head to point to the last node
}
