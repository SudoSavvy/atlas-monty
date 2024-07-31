#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_opcodes - Executes the opcodes from the Monty bytecode file.
 * @file: Pointer to the file containing Monty bytecode.
 * @stack: Pointer to the stack.
 */
void execute_opcodes(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1)
    {
        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || *opcode == '#') /* Skip empty lines or comments */
        {
            line_number++;
            continue;
        }

        if (strcmp(opcode, "push") == 0)
        {
            char *arg = strtok(NULL, " \t\n");
            if (arg == NULL || !is_number(arg))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(stack, atoi(arg));
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    free(line);
}
