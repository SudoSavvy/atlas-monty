#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *top1, *top2;
    int sum;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top1 = *stack;
    top2 = top1->next;

    sum = top1->n + top2->n;

    top2->n = sum;
    *stack = top2;
    free(top1);
}