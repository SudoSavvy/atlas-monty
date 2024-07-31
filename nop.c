#include "monty.h"
#include <stdio.h>

/**
 * nop - No operation
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* Does nothing */
}
