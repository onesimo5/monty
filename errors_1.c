#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);


/**
 * usage_error - Usage error.
 * Return: all the time (EXIT_FAILURE).
 */



int usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}



/**
 * malloc_error - Memory alloc error message.
 * Return: All the time (EXIT_FAILURE).
 */


int malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}



/**
 * f_open_error - Prints error messages.
 * @filename: Failed file openieng
 * Return: must (EXIT_FAILURE).
 */


int f_open_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}


/**
 * unknown_op_error - error messages print.
 * @opcode: wherever error is
 * @line_number: where error occurs
 * Return: must (EXIT_FAILURE).
 */


int unknown_op_error(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
        line_number, opcode);
    return (EXIT_FAILURE);
}




/**
 * no_int_error - monty_push error messages to be printed.
 * @line_number: Where error occurres.
 * Return: must (EXIT_FAILURE).
 */


int no_int_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}
