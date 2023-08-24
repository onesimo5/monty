#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);


/**
 * pop_error - Prints pop error messages.
 * @line_number: number of line where error occ.
 * Return: must (EXIT_FAILURE).
 */


int pop_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * pint_error - Prints pint error messages for empty stacks.
 * @line_number: Line number where error occurred.
 * Return: must (EXIT_FAILURE).
 */


int pint_error(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * short_stack_error - Monty math func.
 * @line_number: Line number where error occurred.
 * @op: Op where err occured.
 * Return: must (EXIT_FAILURE).
 */


int short_stack_error(unsigned int line_number, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
    return (EXIT_FAILURE);
}


/**
 * div_error - Division error messages
 * @line_number: Line number where error occ.
 * Return: must (EXIT_FAILURE).
 */


int div_error(unsigned int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    return (EXIT_FAILURE);
}


/**
 * pchar_error - Error messages for empty stacks.
 * @line_number: Line number where error happened.
 * @message: Error message to be printed.
 * Return: must (EXIT_FAILURE).
 */


int pchar_error(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
    return (EXIT_FAILURE);
}
