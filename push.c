#include "monty.h"
#include <ctype.h>

void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int n;

    if (arg == NULL || !isdigit(*arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
