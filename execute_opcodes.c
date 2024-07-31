#include "monty.h"
#include <string.h>  // For strtok and strcmp

void execute_opcodes(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;
    char *opcode, *arg;

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Remove trailing newline character if present
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        // Skip empty lines
        if (line[0] == '\0')
        {
            line_number++;
            continue;
        }

        // Tokenize the line
        opcode = strtok(line, " \t");
        arg = strtok(NULL, " \t");

        // Handle opcode
        if (opcode)
        {
            if (strcmp(opcode, "push") == 0)
                push(stack, line_number);
            else if (strcmp(opcode, "pint") == 0)
                pint(stack, line_number);
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                free(line);
                exit(EXIT_FAILURE);
            }
        }

        line_number++;
    }

    free(line);
}
