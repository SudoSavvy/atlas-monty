#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *second;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *stack = second;
}
