#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_opcodes - Executes the opcodes from the file
 * @file: The file pointer to the bytecode file
 * @stack: Pointer to the stack
 */
void execute_opcodes(FILE *file, stack_t **stack)
{
    char line[1024];
    char *opcode, *arg;
    unsigned int line_number = 1;

    while (fgets(line, sizeof(line), file))
    {
        opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
        {
            line_number++;
            continue;
        }
        arg = strtok(NULL, " \t\n");

        if (strcmp(opcode, "push") == 0)
        {
            push(stack, line_number, arg);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(stack);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(stack, line_number);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop(stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }
}
