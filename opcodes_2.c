#include "monty.h"

void add(stack_t **head, int line_number){
    stack_t *first, *second;
    first = *head;
    int sum = 0;
    second = first->next;

    if (!second)
    {
        fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    sum = first->n + second->n;

    pop(head, line_number);

    (*head)->n = sum;
}

void sub(stack_t **head, int line_number){
    stack_t *first, *second;
    first = *head;
    int sum = 0;
    second = first->next;

    if (!second)
    {
        fprintf(stderr, "L<%d>: can't sub, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    sum = second->n - first->n;

    pop(head, line_number);

    (*head)->n = sum;
}

void divi(stack_t **head, int line_number){
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
        fprintf(stderr, "L<%d>: can't div, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    sum = second->n / first->n;

    pop(head, line_number);

    (*head)->n = sum;
}

void mul(stack_t **head, int line_number){
    stack_t *first, *second;
    first = *head;
    int sum = 0;
    second = first->next;

    if (!second)
    {
        fprintf(stderr, "L<%d>: can't mul, stack too short", line_number);
        exit(EXIT_FAILURE);
    }

    sum = first->n * second->n;

    pop(head, line_number);

    (*head)->n = sum;
}
