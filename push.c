#include "monty.h"
#include <ctype.h>   // For isdigit
#include <stdlib.h>  // For atoi
#include <string.h>  // For strtok

void push(stack_t **stack, unsigned int line_number, char *arg)
{
    int value;

    if (arg == NULL || !isdigit(*arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}
