#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void execute_opcodes(FILE *file, stack_t **stack);

int main(int argc, char **argv)
{
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    execute_opcodes(file, &stack);

    fclose(file);
    return (EXIT_SUCCESS);
}

void execute_opcodes(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Parse and execute each line */
        /* For simplicity, assuming only 'push' and 'pint' instructions */
        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || *opcode == '#')  /* Skip empty lines or comments */
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
