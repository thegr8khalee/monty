#include "monty.h"

int is_int(char *str) {
    if (!str || *str == '\0') {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

void free_stack(stack_t *head){
    stack_t *temp = head;

    while(temp != NULL){
        temp = temp->next;
        free(temp);
    }
    free(head);
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    if (!lineptr || !n || !stream) {
        return -1;
    }

    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t chars_read = 0;

    int c;
    while ((c = fgetc(stream)) != EOF) {
        if (chars_read + 1 >= bufsize) {
            bufsize += 128;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                free(buffer);
                return -1;
            }
        }
        buffer[chars_read++] = c;
        if (c == '\n') {
            break;
        }
    }

    if (chars_read == 0 && c == EOF) {
        free(buffer);
        return -1;
    }

    buffer[chars_read] = '\0';
    *lineptr = buffer;
    *n = bufsize;
    return chars_read;
}

void set_stack_mode(int line_number)
{
    (void)line_number; // Unused parameter
    mode = 0; // Set mode to stack (LIFO)
}

void set_queue_mode(int line_number)
{
    (void)line_number; // Unused parameter
    mode = 1; // Set mode to queue (FIFO)
}