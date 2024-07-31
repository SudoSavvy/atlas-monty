#include "monty.h"

int main(int argc, char **argv)
{
    stack_t *stack = NULL;
    unsigned int line_number = 1; /* Example line number */

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Initialize and run your Monty interpreter here */

    fclose(file);
    return (EXIT_SUCCESS);
}
