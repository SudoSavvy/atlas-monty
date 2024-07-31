#include "monty.h"

/**
 * nop - A no-operation function that does nothing
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 *
 * Return: None
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;       // Unused parameter
    (void)line_number; // Unused parameter
}
