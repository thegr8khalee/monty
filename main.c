#include "monty.h"

int mode = 0;

void main(int argc, char **argv)
{
    FILE *file;
    int line_number = 0;
    size_t len = 0;
    stack_t *stack = NULL;
    char *line = NULL, *opcode, *arg;

    if (argc < 2 || argc > 2)
    {
        fprintf(stderr, "USAGE: monty file");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file <%s>", argv[1]);
        exit(EXIT_FAILURE);
    }

    // ssize_t use = getline(&line, &len, file);
    // printf("%li", use);
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode = strtok(line, " \t\n$");
        // printf("%s\n", opcode);
        if (!opcode || opcode[0] == '#')
            continue;

        arg = strtok(NULL, " \t\n$");
        // printf("%s\n", arg);
        if (strcmp(opcode, "push") == 0)
            push(&stack, line_number, arg);
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack);
        else if (strcmp(opcode, "pint") == 0)
            pint(&stack, line_number);
        else if (strcmp(opcode, "pop") == 0)
            pop(&stack, line_number);
        else if (strcmp(opcode, "swap") == 0)
            swap(&stack, line_number);
        else if (strcmp(opcode, "add") == 0)
            add(&stack, line_number);
        else if (strcmp(opcode, "nop") == 0)
            continue;
        else if (strcmp(opcode, "sub") == 0)
            sub(&stack, line_number);
        else if (strcmp(opcode, "divi") == 0)
            divi(&stack, line_number);
        else if (strcmp(opcode, "mul") == 0)
            mul(&stack, line_number);
        else if (strcmp(opcode, "mod") == 0)
            mod(&stack, line_number);
        else if (strcmp(opcode, "pchar") == 0)
            pchar(&stack, line_number);
        else if (strcmp(opcode, "pstr") == 0)
            pstr(&stack, line_number);
        else if (strcmp(opcode, "rotl") == 0)
            rotl(&stack, line_number);
        else if (strcmp(opcode, "rotr") == 0)
            rotr(&stack, line_number);
        else if (strcmp(opcode, "stack") == 0)
            set_stack_mode(line_number);
        else if (strcmp(opcode, "queue") == 0)
            set_queue_mode(line_number);
        else
        {
            fprintf(stderr, "L<%u>: unknown instruction %s\n", line_number, opcode);
            free_stack(stack);
            fclose(file);
            free(line);
            exit(EXIT_FAILURE);
        }
        //pall(&stack);
    }
}