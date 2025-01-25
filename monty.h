#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int is_int(char *str);
void free_stack(stack_t *head);
void push(stack_t **head, int line_number, char *arg);
void pint(stack_t **head, int line_number);
void pall(stack_t **head);
void pop(stack_t **head, int line_number);
void swap(stack_t **head, int line_number);
void add(stack_t **head, int line_number);
void sub(stack_t **head, int line_number);
void divi(stack_t **head, int line_number);
void mul(stack_t **head, int line_number);
void mod(stack_t **head, int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void pchar(stack_t **head, int line_number);
void pstr(stack_t **head, int line_number);
void rotl(stack_t **head, int line_number);
void rotr(stack_t **head, int line_number);
void set_stack_mode(int line_number);
void set_queue_mode(int line_number);

extern int mode;

#endif