#include "monty.h"

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},  // Add pint to the instruction set
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
