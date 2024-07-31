#include "monty.h"
#include <ctype.h>
int is_number(const char *str);

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current operation.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int n;

    if (arg == NULL || !is_number(arg))
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

/**
 * is_number - Checks if a string is a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_number(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return 0;
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}
