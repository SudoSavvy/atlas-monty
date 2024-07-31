#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *second;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    second = (*stack)->next;

    // Debugging statement
    printf("Adding top two elements: %d + %d\n", top->n, second->n);

    // Perform the addition
    second->n += top->n;

    // Remove the top element
    second->next = top->next;
    if (top->next != NULL)
        top->next->prev = second;

    free(top);

    // Update the stack pointer
    *stack = second;

    // Debugging statement
    printf("New top of stack after addition: %d\n", (*stack)->n);
}